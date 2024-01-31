# Python packages
import sys
from enum import Enum
import math
import numpy as np
from array import array
import os
from ament_index_python.packages import get_package_share_directory
import yaml
import random

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from rclpy.qos import QoSProfile, QoSDurabilityPolicy
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from tf_transformations import euler_from_quaternion
from geometry_msgs.msg import Twist, PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from nav2_simple_commander.costmap_2d import PyCostmap2D
from nav_msgs.msg import OccupancyGrid, Odometry
from nav_msgs.srv import GetMap

# Assessment dependencies
from assessment_interfaces.msg import ItemList, ItemHolders, RobotList, HomeZone

# Solution Dependencies
from solution_interfaces.msg import WorldItem, Clusters
from solution_interfaces.srv import InitialPose


class State(Enum):
    SPAWN = 0 # Search for an item to collect
    NAVIGATE = 1 # Navigate to a point where there are items to collect
    PICKUP = 2 # Drive into an object in sight
    RETURN = 3 # Return home to drop off item
    SET_GOAL = 4 
    EVALUATE = 5 # Evaluate which cluster to collect from

CAMERA_FOCAL_DISTANCE = 540
BALL_DIAMETER = 0.15
MIN_ITEM_DIAMETER_READING = 20
MAX_ITEM_DIAMETER_READING = 200
CLOSE_ITEM_THRESHOLD = 135
# MIN_DISTANCE = 0.26
# MAX_DISTANCE = 4.18
MAX_ANGLE_READING = 170
ANGLE_COEF = 29 / 290 # This coeficient transforms the x pixel coordinate of item.x to the angle between the robot line of sight and the item

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        # Initial params
        self.state = State.SPAWN
        self.pose = None
        self.yaw = 0.0
        self.navigator = BasicNavigator()
        self.items = []
        self.item_holders = []
        self.clusters = []
        self.taken_clusters = []
        self.new_clusters = False # Records wether new clusters were detected since last reevaluation
        self.goal = None
        self.current_cluster = None
        self.map = None
        self.colour = "RED"
        self.robots = [] # A list of Robot.msg items describing robots seen through the camera
        self.home_zone = None # The reading from the home_zone topic
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

        self.initial_pose_cli = self.create_client(InitialPose, '/initial_pose', callback_group=client_cb_group)
        while not self.initial_pose_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Initial Pose service not available, waiting again...')
        self.initial_pose_req = InitialPose.Request()
        self.log("Connected to Initial Pose service")

        # Get the costmap object
        response = self.send_request(self.map_cli, self.map_req)
        self.occupancy_grid = response.map
        self.map = PyCostmap2D(self.occupancy_grid)
        self.log("Obtained map object")
        self.maps = {
            'RED': self.occupancy_grid,
            'GREEN': self.occupancy_grid,
            'BLUE': self.occupancy_grid,
        }

        # Set initial pose
        self.initial_pose_req.robot_id = self.get_namespace()[1:]
        response = self.send_request(self.initial_pose_cli, self.initial_pose_req)

        self.initial_pose = PoseStamped()
        self.initial_pose.header.frame_id = 'map'
        self.initial_pose.header.stamp = self.get_clock().now().to_msg()
        self.initial_pose.pose.position.x = response.x
        self.initial_pose.pose.position.y = response.y
        self.initial_pose.pose.orientation.z = 0.0
        self.initial_pose.pose.orientation.w = 1.0
        self.navigator.setInitialPose(self.initial_pose)

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
        
        self.clusters_subscriber = self.create_subscription(
            Clusters,
            "/clusters",
            self.clusters_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.item_holders_subsrcriber = self.create_subscription(
            ItemHolders,
            "/item_holders",
            self.item_holders_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.red_map_subscriber = self.create_subscription(
            OccupancyGrid,
            "/RED",
            self.red_map_callback,
            10,
            callback_group=subscription_cb_roup)

        self.green_map_subscriber = self.create_subscription(
            OccupancyGrid,
            "/GREEN",
            self.green_map_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.blue_map_subscriber = self.create_subscription(
            OccupancyGrid,
            "/BLUE",
            self.blue_map_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.robots_subsrcriber = self.create_subscription(
            RobotList,
            "robots",
            self.robots_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.home_zone_subsrcriber = self.create_subscription(
            HomeZone,
            "home_zone",
            self.home_zone_callback,
            10,
            callback_group=subscription_cb_roup)


        ### PUBLISHERS ###
        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10, callback_group=publisher_cb_group)
        qos = QoSProfile(durability = QoSDurabilityPolicy.TRANSIENT_LOCAL,
                         depth = 10)
        self.occupancy_grid_publisher = self.create_publisher(OccupancyGrid, 'map', qos, callback_group=publisher_cb_group)
        self.world_item_publisher = self.create_publisher(WorldItem, '/world_items', 10, callback_group=publisher_cb_group)

        
        self.time_alive = 0
        self.last_reeval = 0
        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop, callback_group=timer_cb_group)
        

    def send_request(self, client, request):
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        return future.result()
    

    def odom_callback(self, msg):
        self.pose = msg.pose.pose

        (roll, pitch, yaw) = euler_from_quaternion([self.pose.orientation.x,
                                                    self.pose.orientation.y,
                                                    self.pose.orientation.z,
                                                    self.pose.orientation.w])
        
        self.yaw = yaw
    

    def item_callback(self, msg):
        self.items = msg.data


    def clusters_callback(self, msg):
        self.clusters = msg.clusters
        self.new_clusters = True


    def item_holders_callback(self, msg):
        self.item_holders = msg.data


    def robots_callback(self, msg):
        self.robots = msg.data

    def home_zone_callback(self, msg):
        self.home_zone = msg

    def red_map_callback(self, msg):
        self.maps["RED"] = msg
        if self.colour == "RED":
            self.setMap(self.colour)


    def green_map_callback(self, msg):
        self.maps["GREEN"] = msg
        if self.colour == "GREEN":
            self.setMap(self.colour)


    def blue_map_callback(self, msg):
        self.maps['BLUE'] = msg
        if self.colour == "BLUE":
            self.setMap(self.colour)


    def setMap(self, colour):
        self.occupancy_grid_publisher.publish(self.maps[colour])


    def evaluate_path(self, path, colour, bonus):
        match colour:
            case "RED":
                value = 5
            case "GREEN":
                value = 10
            case "BLUE":
                value = 15

        value += bonus
        
        distance = 0
        for i in range(len(path.poses) - 1):
            position_a_x = path.poses[i].pose.position.x
            position_b_x = path.poses[i+1].pose.position.x
            position_a_y = path.poses[i].pose.position.y
            position_b_y = path.poses[i+1].pose.position.y

            distance += np.sqrt(np.power((position_b_x - position_a_x), 2) + np.power((position_b_y- position_a_y), 2))
        
        return value / distance

    
    def evaluate(self):
        self.log(f"Evaluating with {len(self.taken_clusters)} taken clusters out of {len(self.clusters)} clusters")
        if self.clusters == []:
            return

        best_value = None
        best_cluster = None
        best_goal = None
        # iterate through the clusters to find the best one
        
        for cluster in self.clusters:
            if any(math.isclose(cluster.x, c.x, abs_tol=0.1) and math.isclose(cluster.y, c.y, abs_tol=0.1) for c in self.taken_clusters):
                self.log("Ignoring taken cluster")
                continue
            # If this cluster is taken, ignore it
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = self.get_clock().now().to_msg()
            goal_pose.pose.position.x = cluster.x
            goal_pose.pose.position.y = cluster.y
            goal_pose.pose.orientation.z = 0.0
            goal_pose.pose.orientation.w = 1.0

            start_pose = PoseStamped()
            start_pose.header.frame_id = 'map'
            start_pose.header.stamp = self.get_clock().now().to_msg()
            start_pose.pose = self.pose

            self.setMap(cluster.colour)
            path = self.navigator.getPath(self.initial_pose, goal_pose)

            # Promote clusters that are far on the "x" axis
            bonus = math.fabs((self.initial_pose.pose.position.x - goal_pose.pose.position.x))
            # Calculate penalties to encourage robots to "stay in their lane"
            bonus += (-2) * math.fabs((self.initial_pose.pose.position.y - goal_pose.pose.position.y))

            value = self.evaluate_path(path, cluster.colour, bonus)

            if best_value is None or value > best_value:
                best_value = value
                best_cluster = cluster
                best_goal = goal_pose

        self.new_clusters = False
    
        self.log(f"New GOAL selected!")
        self.goal = best_goal
        self.current_cluster = best_cluster
        ## Added noise to reduce chances of robots coliding with eachother
        self.colour = best_cluster.colour
        self.setMap(self.colour)

    
    def log(self, text):
        self.get_logger().info(f"[{self.get_namespace()}]: {text}")


    def get_distance_to_item(self, diameter):
        distance = BALL_DIAMETER * CAMERA_FOCAL_DISTANCE / diameter
        return distance


    def publish_items(self):
        if self.pose is None or self.robots != []:
            return
        for i, item in enumerate(self.items):
            
            if math.fabs(item.x) < MAX_ANGLE_READING and item.diameter >= MIN_ITEM_DIAMETER_READING and item.diameter <= MAX_ITEM_DIAMETER_READING:
                distance = self.get_distance_to_item(item.diameter)
                angle = math.degrees(self.yaw) + item.x * ANGLE_COEF
                dy = distance * math.sin(math.radians(angle))
                dx = distance * math.cos(math.radians(angle))
                world_item = WorldItem()
                world_item.x = self.pose.position.x + dx
                world_item.y = self.pose.position.y + dy
                world_item.colour = item.colour
                self.world_item_publisher.publish(world_item)


    def has_item(self):
        for robot in self.item_holders:
            if "/" + robot.robot_id == self.get_namespace() and robot.holding_item:
                return True
        return False


    def get_closest_item(self):
        result = None
        for item in self.items:
            if item.colour == self.colour and \
               item.diameter >= CLOSE_ITEM_THRESHOLD and \
               (result is None or item.diameter > result.diameter):
                result = item
        return result


    def control_loop(self):
        self.time_alive += self.timer_period
        self.publish_items()
        
        if self.has_item() and self.state != State.RETURN:
            self.log("Going into RETURN state")
            msg = Twist()
            self.cmd_vel_publisher.publish(msg)
            self.navigator.goToPose(self.initial_pose)
            self.state = State.RETURN
        
        match self.state:
            case State.SPAWN:
                if self.time_alive > 1:
                    self.log("Going into EVALUATE state")
                    self.state = State.EVALUATE
            
            case State.EVALUATE:
                self.evaluate()
                if self.goal is not None:
                    self.log("Going into SET_GOAL state")
                    self.state = State.SET_GOAL

            case State.SET_GOAL:
                if self.goal != None:
                    self.log(f"Navigating to goal!")
                    self.navigator.goToPose(self.goal)
                    self.state = State.NAVIGATE

            case State.NAVIGATE:
                if any(r.size > 0.009 and math.fabs(r.x) < 150 for r in self.robots) and self.time_alive - self.last_reeval > 5:
                    self.last_reeval = self.time_alive
                    self.log(self.robots[0].x)
                    self.log("Found robot potentially heading into the same direction. Reevaluating")
                    self.taken_clusters.append(self.current_cluster)
                    self.state = State.EVALUATE

                elif self.get_closest_item() is not None:
                    self.log("Going into PICKUP state")
                    self.navigator.cancelTask()
                    self.state = State.PICKUP

                elif self.navigator.isTaskComplete():
                    msg = Twist()
                    msg.angular.z = -0.8
                    self.cmd_vel_publisher.publish(msg)
                # if self.navigator.isTaskComplete() and self.get_closest_item() is None:


            case State.PICKUP:
                msg = Twist()
                closest_item = self.get_closest_item()
                if closest_item is None:
                    msg.linear.x = 0.5
                elif math.fabs(closest_item.x) > 25:
                    msg.linear.x = 0.1 # This stops the robot from getting stuck on choosing between 2 equally close objects
                    msg.angular.z = closest_item.x / 320.0 * 0.8
                else:
                    msg.linear.x = 1.0
                    
                self.cmd_vel_publisher.publish(msg)

            case State.RETURN:
                # if any(r.size > 0.5 for r in self.robots):
                #         self.log("Another robot encountered")
                #         self.taken_clusters.append(self.current_cluster)

                if not self.has_item():
                    self.log("Going into EVALUATE state")
                    self.navigator.cancelTask()
                    self.state = State.EVALUATE

                # elif self.navigator.isTaskComplete():
                #     self.log("Going into EVALUATE state")
                #     self.state = State.EVALUATE
                # if self.home_zone is not None and self.home_zone.visible and self.home_zone.size > 0.7 and self.robots == []:
                #     msg = Twist()
                #     msg.angular.z = self.home_zone.x / 320.0 * 2.0
                #     self.cmd_vel_publisher.publish(msg)
                #     # self.navigator.cancelTask()
                        

    def destroy_node(self):
        super().destroy_node()


def main(args=None):

    rclpy.init(args = args, signal_handler_options = SignalHandlerOptions.NO)

    node = RobotController()

    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()