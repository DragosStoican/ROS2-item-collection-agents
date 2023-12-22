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

# Assessment dependencies
from assessment_interfaces.msg import ItemList

# Solution Dependencies
from solution_interfaces.msg import WorldItem
from solution_interfaces.srv import GetClusters


class State(Enum):
    SEARCH = 0 # Search for an item to collect
    NAVIGATE = 1 # Navigate to a point where there are items to collect
    PICKUP = 2 # Drive into an object in sight
    RETURN = 3 # Return home to drop off item
    EVALUATE = 4 # Reevaluate weather there is a better cluster to collect from

CAMERA_FOCAL_DISTANCE = 540
BALL_DIAMETER = 0.15
MIN_ITEM_DIAMETER = 20
MAX_ITEM_DIAMETER = 450
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
        self.world_items = {
            'RED': [],
            'GREEN': [],
            'BLUE': [],
        }
        self.map = None
        self.test = True
        self.colour = None
        client_cb_group = MutuallyExclusiveCallbackGroup()
        timer_cb_group = MutuallyExclusiveCallbackGroup()
        subscription_cb_roup = MutuallyExclusiveCallbackGroup()
        Publisher_cb_group = MutuallyExclusiveCallbackGroup()
        
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


        ### PUBLISHERS ###
        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10, callback_group=Publisher_cb_group)
        qos = QoSProfile(durability = QoSDurabilityPolicy.TRANSIENT_LOCAL,
                         depth = 10)
        self.occupancy_grid_punlisher = self.create_publisher(OccupancyGrid, 'map', qos, callback_group=Publisher_cb_group)
        self.world_item_publisher = self.create_publisher(WorldItem, '/world_items', 10, callback_group=Publisher_cb_group)


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
        rclpy.spin_until_future_complete(self, future)
        return future.result()
    

    def item_callback(self, msg):
        self.items = msg.data
        self.log("Item callback")

    
    def world_items_callback(self, msg):
        self.world_items[msg.colour].append((msg.x, msg.y))
        if self.colour is None or self.colour == msg.colour:
            self.add_item_to_costmap(msg.x, msg.y)

    
    def add_item_to_costmap(self, x, y):
        """
        Adds item at real location x and y to the costmap of the robot
        """
        x, y = self.map.worldToMap(x, y)
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
        self.get_logger().info(text)


    def get_distance_to_item(self, diameter):
        distance = BALL_DIAMETER * CAMERA_FOCAL_DISTANCE / diameter
        return distance


    def publish_items(self):
        self.log(f"publishing item {self.items}")
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
                self.log("publishing item")
                self.world_item_publisher.publish(world_item)


    def control_loop(self):
        # # colour = self.get_parameter('colour').get_parameter_value().string_value
        match self.state:
            case State.SEARCH:
                self.log("HELLOO")
                self.publish_items()
                if self.test:
                    self.log("Sending clusters request")
                    clusters = self.send_request(self.cluster_cli, self.clusters_req).clusters
                    self.log(f"Done with the request: {clusters}")
                    if len(clusters) == 6:
                        self.log("6 Clusters!!")
                        self.test = False
                    self.log(f"Done loop")
                    self.test = False

                        

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

    # try:
    #     rclpy.spin(node)
    # except KeyboardInterrupt:
    #     pass
    # except ExternalShutdownException:
    #     sys.exit(1)
    # finally:
    #     node.destroy_node()
    #     rclpy.try_shutdown()


if __name__ == '__main__':
    main()