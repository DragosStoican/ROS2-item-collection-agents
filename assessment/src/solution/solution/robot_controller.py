# Python packages
import sys
from enum import Enum
import math
import numpy as np
from array import array

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from rclpy.qos import QoSProfile, QoSDurabilityPolicy
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from tf_transformations import euler_from_quaternion
from geometry_msgs.msg import Twist, Pose, PoseStamped
from std_msgs.msg import String
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from nav2_simple_commander.costmap_2d import PyCostmap2D
from nav_msgs.msg import OccupancyGrid, Odometry
from nav_msgs.srv import GetMap
from visualization_msgs.msg import Marker, MarkerArray
from rclpy.duration import Duration

# Assessment dependencies
from assessment_interfaces.msg import ItemList, ItemHolders

# Solution Dependencies
from solution_interfaces.msg import WorldItem
from solution_interfaces.srv import GetClusters


class State(Enum):
    SEARCH = 0 # Search for an item to collect
    NAVIGATE = 1 # Navigate to a point where there are items to collect
    PICKUP = 2 # Drive into an object in sight
    RETURN = 3 # Return home to drop off item
    SET_GOAL = 4 # Reevaluate weather there is a better cluster to collect from

CAMERA_FOCAL_DISTANCE = 540
BALL_DIAMETER = 0.15
MIN_ITEM_DIAMETER = 20
MAX_ITEM_DIAMETER = 450
CLOSE_ITEM_THRESHOLD = 100
# MIN_DISTANCE = 0.26
# MAX_DISTANCE = 4.18
MAX_ANGLE_READING = 170
ANGLE_COEF = 29 / 290 # This coeficient transforms the x pixel coordinate of item.x to the angle between the robot line of sight and the item

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        # Initial params
        self.declare_parameter('colour', '')
        self.state = State.SEARCH
        self.pose = Pose()
        self.yaw = 0.0
        self.navigator = BasicNavigator()
        self.items = []
        self.item_holders = []
        self.map_items = {
            'RED': [],
            'GREEN': [],
            'BLUE': [],
        }
        self.goal = None
        self.map = None
        self.test = True
        self.colour = None
        client_cb_group = MutuallyExclusiveCallbackGroup()
        timer_cb_group = MutuallyExclusiveCallbackGroup()
        subscription_cb_roup = MutuallyExclusiveCallbackGroup()
        publisher_cb_group = MutuallyExclusiveCallbackGroup()
        
        # Service clients
        self.map_cli = self.create_client(GetMap, 'map_server/map', callback_group=client_cb_group)
        while not self.map_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Map service not available, waiting again...')
        self.map_req = GetMap.Request()
        self.log("Connected to map service")

        self.cluster_cli = self.create_client(GetClusters, '/clusters', callback_group=client_cb_group)
        while not self.cluster_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Cluster service not available, waiting again...')
        self.clusters_req = GetClusters.Request()
        self.log("Connected to clusters service")

        # Get the costmap object
        response = self.send_request(self.map_cli, self.map_req)
        self.empty_occupancy_grid = response.map
        self.occupancy_grid = response.map
        self.map = PyCostmap2D(self.occupancy_grid)
        self.log("Obtained map object")

        # Set initial pose
        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        initial_pose.pose.position.x = -3.5
        initial_pose.pose.position.y = 0.0
        initial_pose.pose.orientation.z = 0.0
        initial_pose.pose.orientation.w = 1.0
        self.navigator.setInitialPose(initial_pose)

        self.navigator.waitUntilNav2Active()


        ### SUBSRCIBERS ###
        self.odom_subscriber = self.create_subscription(
            Odometry,
            'odom',
            self.odom_callback,
            10,
            callback_group=subscription_cb_roup)

        self.item_subscriber = self.create_subscription(
            ItemList,
            'items',
            self.item_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.world_item_subscriber = self.create_subscription(
            WorldItem,
            "/world_items",
            self.world_items_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.clusters_markers_subscriber = self.create_subscription(
            MarkerArray,
            "/clusters_markers",
            self.clusters_markers_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.item_holders_subsrcriber = self.create_subscription(
            ItemHolders,
            "/item_holders",
            self.item_holders_callback,
            10,
            callback_group=subscription_cb_roup)


        ### PUBLISHERS ###
        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10, callback_group=publisher_cb_group)
        qos = QoSProfile(durability = QoSDurabilityPolicy.TRANSIENT_LOCAL,
                         depth = 10)
        self.occupancy_grid_punlisher = self.create_publisher(OccupancyGrid, 'map', qos, callback_group=publisher_cb_group)
        self.world_item_publisher = self.create_publisher(WorldItem, '/world_items', 10, callback_group=publisher_cb_group)


        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop, callback_group=timer_cb_group)


    def odom_callback(self, msg):
        self.pose = msg.pose.pose

        (roll, pitch, yaw) = euler_from_quaternion([self.pose.orientation.x,
                                                    self.pose.orientation.y,
                                                    self.pose.orientation.z,
                                                    self.pose.orientation.w])
        
        self.yaw = yaw


    def send_request(self, client, request):
        future = client.call_async(request)
        if self.executor is None:
            rclpy.spin_until_future_complete(self, future)
        else:
            self.executor.spin_until_future_complete(future)
        return future.result()
    

    def item_callback(self, msg):
        self.items = msg.data


    def clusters_markers_callback(self, msg):
        markers = msg.markers
        # TODO: Iterate through clusters
        cluster = markers[0]
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.header.stamp = self.get_clock().now().to_msg()
        goal_pose.pose.position.x = cluster.pose.position.x
        goal_pose.pose.position.y = cluster.pose.position.y
        goal_pose.pose.orientation.w = 1.0

        # self.log(f"Setting new goal!")
        self.goal = goal_pose


    def item_holders_callback(self, msg):
        self.item_holders = msg.data


    def world_items_callback(self, msg):
        # TODO: Maybe map update should only happen when at home
        x_map, y_map = self.map.worldToMap(msg.x, msg.y)
        if not self.item_on_map(msg.colour, x_map, y_map):
            self.map_items[msg.colour].append((x_map, y_map))
            self.add_item_to_costmap(x_map, y_map)


    def item_on_map(self, colour, x, y) -> bool:
        x_map, y_map = self.map.worldToMap(x, y)
        for item in self.map_items[colour]:
            if item[0] == x and item[1] == y:
                return True
        return False

    def add_item_to_costmap(self, x, y):
        """
        Adds item at map location x and y to the costmap of the robot
        """
        self.map.setCost(x, y, 100)
        self.updateMap()

    
    def updateMap(self):
        old_grid = self.occupancy_grid.data
        new_grid = array('b', self.map.costmap)
        if old_grid != new_grid:
            self.occupancy_grid.data = new_grid
            self.get_logger().info("Puiblishing to /robot1/map")
            self.occupancy_grid_punlisher.publish(self.occupancy_grid)

    
    def log(self, text: str):
        self.get_logger().info(f"[{self.get_namespace()}]: {text}")


    def get_distance_to_item(self, diameter):
        distance = BALL_DIAMETER * CAMERA_FOCAL_DISTANCE / diameter
        return distance


    def publish_items(self):
        for i, item in enumerate(self.items):
            if math.fabs(item.x) < MAX_ANGLE_READING and item.diameter >= MIN_ITEM_DIAMETER:
                distance = self.get_distance_to_item(item.diameter)
                angle = math.degrees(self.yaw) + item.x * ANGLE_COEF
                dy = distance * math.sin(math.radians(angle))
                dx = distance * math.cos(math.radians(angle))
                world_item = WorldItem()
                world_item.x = self.pose.position.x + dx
                world_item.y = self.pose.position.y + dy
                world_item.colour = item.colour
                x_map, y_map = self.map.worldToMap(world_item.x, world_item.y)
                if not self.item_on_map(world_item.colour, x_map, y_map):
                    self.world_item_publisher.publish(world_item)


    def has_item(self):
        if self.item_holders != []:
            self.log(f"{self.item_holders}")
        for robot in self.item_holders:
            if "/" + robot.robot_id == self.get_namespace() and robot.holding_item:
                self.log(f"holding an item!")
                return True
        return False


    def get_closest_item(self):
        result = None
        for item in self.items:
            if item.diameter >= CLOSE_ITEM_THRESHOLD and (result is None or item.diameter > result.diameter):
                result = item
        return result


    def control_loop(self):
        self.publish_items()
        if self.has_item():
            self.log("Going into RETURN state")
            self.state = State.RETURN
        
        match self.state:
            case State.SEARCH:
                # TODO: Logic for scout/pickupers
                self.state = State.SET_GOAL
                # goal_pose = PoseStamped()
                # goal_pose.header.frame_id = 'map'
                # goal_pose.header.stamp = self.get_clock().now().to_msg()
                # goal_pose.pose.position.x = -1.35
                # goal_pose.pose.position.y = -0.14
                # goal_pose.pose.orientation.w = 1.0

                # self.goal = goal_pose
                # self.navigator.goToPose(self.goal)
                # self.state = State.NAVIGATE
            case State.SET_GOAL:
                if self.goal != None:
                    self.log(f"Setting new goal!")
                    self.navigator.goToPose(self.goal)
                    self.state = State.NAVIGATE
            case State.NAVIGATE:
                if self.get_closest_item() is not None:
                        self.log("Going into PICKUP state")
                        self.navigator.cancelTask()
                        self.state = State.PICKUP
                        
            case State.PICKUP:
                msg = Twist()
                closest_item = self.get_closest_item()
                if closest_item is None:
                    msg.linear.x = 1.0
                elif math.fabs(closest_item.x) > 10:
                    msg.angular.z = closest_item.x / 320.0
                else:
                    msg.linear.x = 2.0
                self.cmd_vel_publisher.publish(msg)
                

            case State.RETURN:
                pass

        # match self.state:
        #     case State.SEARCH:                
        #         if self.test:
        #             # self.log("Sending clusters request")
        #             # clusters = self.send_request(self.cluster_cli, self.clusters_req).clusters
        #             # self.log(f"Done with the request: {clusters}")
        #             # if len(clusters) == 6:
        #             #     self.log("6 Clusters!!")
        #             self.test = False

                        

    def destroy_node(self):
        super().destroy_node()


def main(args=None):

    rclpy.init(args = args, signal_handler_options = SignalHandlerOptions.NO)

    node = RobotController()

    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt: # TODO: Why does this sometimes take 2x Ctrl+c to kill?
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()