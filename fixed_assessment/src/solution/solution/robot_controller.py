# Python packages
import sys
from enum import Enum
import math
import numpy as np

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from rclpy.qos import QoSProfile, QoSDurabilityPolicy
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from tf_transformations import euler_from_quaternion
from geometry_msgs.msg import Twist, PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
from nav_msgs.msg import OccupancyGrid, Odometry
from nav_msgs.srv import GetMap

# Assessment dependencies
from assessment_interfaces.msg import ItemList, ItemHolders, RobotList, HomeZone

# Solution Dependencies
from solution_interfaces.msg import WorldItem, Clusters
from solution_interfaces.srv import InitialPose


# State class
class State(Enum):
    SPAWN = 0 # Initial state, only after robot creation
    EVALUATE = 1 # Evaluate which cluster to collect from
    SET_GOAL = 2 # Set the goal of the robot navigator
    NAVIGATE = 3 # Navigate to a point where there are items to collect
    PICKUP = 4 # Drive into an object in sight
    RETURN = 5 # Return home to drop off item
    FACE_ARENA = 6 # Spin around until facing the arena after return an item

# Object detection parametes
CAMERA_FOCAL_DISTANCE = 540
BALL_DIAMETER = 0.15
MIN_ITEM_DIAMETER_READING = 15
MAX_ITEM_DIAMETER_READING = 200
NAVIGATE_CLOSE_ITEM_THRESHOLD = 135
CLOSE_ITEM_THRESHOLD = 100
MAX_ANGLE_READING = 200
ANGLE_COEF = 29 / 290 # This coeficient transforms the x pixel coordinate of item.x to the angle between the robot line of sight and the item

# Robot detection parameters
ROBOT_DETECTION_ANGLE_THRESHOLD = 150
ROBOT_DETECTION_SIZE_THRESHOLD = 0.005

# Evaluation parameters
SAME_LANE_MULTIPLIER = {
    "RED": 1.0,
    "GREEN": 1.5,
    "BLUE": 3.5,
}
DIFF_LANE_MULTIPLIER = {
    "RED": 15.0,
    "GREEN": 15.0,
    "BLUE": 15.0,
}

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        ### Initial params ###
        # Robot localisation and navigation
        self.state = State.SPAWN
        self.pose = None
        self.yaw = 0.0
        self.navigator = BasicNavigator()
        self.goal = None

        # Item detection and robot detection
        self.items = []
        self.robots = []
        self.item_holders = []

        # Cluster management
        self.clusters = []
        self.new_clusters = False # Records wether new clusters were detected since last reevaluation
        self.colour = "RED" # The colour of items the robot is set to collect
        
        # Callback groups
        client_cb_group = MutuallyExclusiveCallbackGroup()
        timer_cb_group = MutuallyExclusiveCallbackGroup()
        subscription_cb_roup = MutuallyExclusiveCallbackGroup()
        publisher_cb_group = MutuallyExclusiveCallbackGroup()
        

        ### Service clients ##
        self.map_cli = self.create_client(GetMap, 'map_server/map', callback_group=client_cb_group) # This makes a request to the map server to access the inital occupancy grid
        while not self.map_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Map service not available, waiting again...')
        self.map_req = GetMap.Request()
        self.log("Connected to map service")

        self.initial_pose_cli = self.create_client(InitialPose, '/initial_pose', callback_group=client_cb_group) # This makes a request to the nav_manager to retreive this robots initial pose
        while not self.initial_pose_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Initial Pose service not available, waiting again...')
        self.initial_pose_req = InitialPose.Request()
        self.log("Connected to Initial Pose service")


        ### Params init ###
        # Get the costmap object
        response = self.send_request(self.map_cli, self.map_req)
        self.occupancy_grid = response.map
        self.log("Obtained map object")
        self.maps = { # This dictionary will hold occupancy grids for each collection setup. e.g "RED" contains all the positions of GREEN and BLUE items (which we want to avoid), but not RED items (which we want to collect)
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
        
        self.clusters_subscriber = self.create_subscription( # Get the clusters computed by the cluster_manager
            Clusters,
            "/clusters",
            self.clusters_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.item_holders_subsrcriber = self.create_subscription( # Get info on robots holding items, including itself
            ItemHolders,
            "/item_holders",
            self.item_holders_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.red_map_subscriber = self.create_subscription( # Get updates for the RED map
            OccupancyGrid,
            "/RED",
            self.red_map_callback,
            10,
            callback_group=subscription_cb_roup)

        self.green_map_subscriber = self.create_subscription( # Get updates for the GREEN map
            OccupancyGrid,
            "/GREEN",
            self.green_map_callback,
            10,
            callback_group=subscription_cb_roup)
        
        self.blue_map_subscriber = self.create_subscription( # Get updates for the BLUE map
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


        ### PUBLISHERS ###
        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10, callback_group=publisher_cb_group)
        qos = QoSProfile(durability = QoSDurabilityPolicy.TRANSIENT_LOCAL,
                         depth = 10)
        self.occupancy_grid_publisher = self.create_publisher(OccupancyGrid, 'map', qos, callback_group=publisher_cb_group) # Update the costmap used by the robot. This is the map used by the navigator
        self.world_item_publisher = self.create_publisher(WorldItem, '/world_items', 10, callback_group=publisher_cb_group) # Publish detected items for the worl_items_manager to compute
        self.pickedup_items_publisher = self.create_publisher(WorldItem, '/pickedup_items', 10, callback_group=publisher_cb_group) # Publish pickedup items for the world_item manager to compute

        
        self.time_alive = 0
        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop, callback_group=timer_cb_group)
    

    ### Callbacks ###
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
        """
        Publishes to /map to change the occupancy grid used by the robot

        @param color: color of the map to use. One of ["RED", "GREEN", "BLUE"]
        """
        self.occupancy_grid_publisher.publish(self.maps[colour])


    ### Evaluation ###
    def evaluate(self):
        """
        This function iterates through all clusetrs in self.clusters and picks the best one to set as a goal
        """
        # If there's no clusters just return
        if self.clusters == []:
            return

        best_value = None
        best_cluster = None
        best_goal = None

        # Iterate through the clusters to find the best one
        for cluster in self.clusters:
            # Create the goal pose with the cluster coords
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = self.get_clock().now().to_msg()
            goal_pose.pose.position.x = cluster.x
            goal_pose.pose.position.y = cluster.y
            goal_pose.pose.orientation.z = 0.0
            goal_pose.pose.orientation.w = 1.0

            # If this is a different color than what the robot is currently set for, we must update the map and wait a bit for the update to occur
            if (cluster.colour != self.colour):
                self.colour = cluster.colour
                self.setMap(cluster.colour)
                # Wait for the map to change
                rate = self.create_rate(0.7, self.get_clock())
                rate.sleep()
            
            # Calculate the path to the cluster
            path = self.navigator.getPath(self.initial_pose, goal_pose, use_start=True)

            # Evaluate the value of the cluster
            # self.log(f"Evaluating for {cluster.x} {cluster.y} {cluster.colour}")
            value = self.evaluate_path(path, cluster.colour)

            # If it is better than the best cluster, update the best values
            if best_value is None or value > best_value:
                best_value = value
                best_cluster = cluster
                best_goal = goal_pose

        
        # self.log(f"New GOAL selected!")

        # Mark that we found new clusters and set the goal, color, and map of the robot
        self.new_clusters = False
        self.goal = best_goal
        self.colour = best_cluster.colour
        self.setMap(self.colour)

    def evaluate_path(self, path, colour):
        """
        This function takes in a path to a cluster and the colour of the cluster to compute its 'value'. 
        A cluster with a high value means that the robot can accumulate a lot of points by going back and forth to this cluster

        @param path: path to a cluster
        @param colour: colour of the cluster
        """
        # The value is given by the colour of the items in the cluster
        match colour:
            case "RED":
                value = 5
            case "GREEN":
                value = 10
            case "BLUE":
                value = 15

        # Compute starting points
        start_y = path.poses[0].pose.position.y
        start_x = path.poses[0].pose.position.x

        # Apply 'same lane' bonus
        end_x = path.poses[-1].pose.position.x
        bonus = math.fabs(start_x - end_x) * SAME_LANE_MULTIPLIER[colour]
        value += bonus

        # Compute the total distance from start to finish by iterating through the path's poses
        distance = 0
        max_y_diff = 0
        start_y = path.poses[0].pose.position.y
        for i in range(len(path.poses) - 1):
            position_a_x = path.poses[i].pose.position.x
            position_b_x = path.poses[i+1].pose.position.x
            position_a_y = path.poses[i].pose.position.y
            position_b_y = path.poses[i+1].pose.position.y

            diff = math.fabs(start_y - position_a_y)
            if (diff > max_y_diff):
                max_y_diff = diff

            distance += np.sqrt(np.power((position_b_x - position_a_x), 2) + np.power((position_b_y- position_a_y), 2))

        # Apply 'diff lane' penalty, if the difference is high enough
        if max_y_diff > 0.6:
            penalty = max_y_diff * DIFF_LANE_MULTIPLIER[colour]
            value -= penalty

        # self.log(f"max_y_diff = {max_y_diff}")
        # self.log(f"penalty = {penalty if max_y_diff > 0.6 else 0}")
        # self.log(f"final = {value/distance}")

        return value / distance


    ### Item detection ###
    def publish_items(self):
        """
        This function iterates through the items seen by the robot and publishes them via the world_item_publisher
        """
        # Safety checks
        if self.pose is None or self.robots != []:
            return
        
        # Iterate through the items and publish them
        for i, item in enumerate(self.items):
            # The item must be in the center of the camera and not too far away, or the calculations might be skewed
            if math.fabs(item.x) < MAX_ANGLE_READING and item.diameter >= MIN_ITEM_DIAMETER_READING and item.diameter <= MAX_ITEM_DIAMETER_READING:
                # Get the distance to the item, and the angle in degrees
                distance = self.get_distance_to_item(item.diameter)
                angle = math.degrees(self.yaw) + item.x * ANGLE_COEF

                # Calculate the relative distance from the robots
                dy = distance * math.sin(math.radians(angle))
                dx = distance * math.cos(math.radians(angle))

                # Calculate the absolute location using the relative distance and the robot pose
                world_item = WorldItem()
                world_item.x = self.pose.position.x + dx
                world_item.y = self.pose.position.y + dy
                world_item.colour = item.colour

                # Publish the newfound item
                self.world_item_publisher.publish(world_item)

    def get_distance_to_item(self, diameter):
        """
        This function uses the diameter of the item on the image to calculate how far it is from the robot.
        It uses the camera's focal distance and the diamter of the item, whcih can be customised

        @param diameter: The diameter of the item, as seen in the image
        """
        distance = BALL_DIAMETER * CAMERA_FOCAL_DISTANCE / diameter
        return distance


    ### Robot status ###
    def get_closest_item(self, threshold):
        """
        This functio itereates through the items seen by the robot and finds the closest one.

        @param threshold: threshold for what is considered a close item
        """
        result = None

        # Iterate through the items
        for item in self.items:
            # If the colour mathes the one we are looking for, and the object is close enough, update the closes item
            if item.colour == self.colour and \
               item.diameter >= threshold and \
               (result is None or item.diameter > result.diameter):
                result = item

        # Return the result of the iteration
        return result
    
    def has_item(self):
        """
        This function returns true if the robot is holding an item
        """
        for robot in self.item_holders:
            if "/" + robot.robot_id == self.get_namespace() and robot.holding_item:
                return True
        return False


    ### Control loop ###
    def control_loop(self):
        """
        The control loop manages the state of the robot
        """
        # Keep track of how long the robot has been running for
        self.time_alive += self.timer_period

        # We must publish new items on every loop, regardless of state
        self.publish_items()
        
        # We must check that we haven't picked up an item. The robot could potentially run into an item in multiple states so we must check at all times
        if self.has_item() and self.state != State.RETURN:
            # Stop moving and go back to base
            self.navigator.cancelTask()
            msg = Twist()
            self.cmd_vel_publisher.publish(msg)
            self.navigator.goToPose(self.initial_pose)

            # Publish that the item was picked up, so the maps can be updated
            item = WorldItem()
            item.x = self.pose.position.x
            item.y = self.pose.position.y
            item.colour = self.colour
            self.log("Publishing pickedup item")
            self.pickedup_items_publisher.publish(item)
            
            # Go into RETURN state
            self.log("Going into RETURN state")
            self.state = State.RETURN
        
        match self.state:
            # In SPAWN state, we just wait for a second before starting the robot, in order to give the other nodes time to do their computation
            case State.SPAWN:
                if self.time_alive > 1:
                    self.log("Going into EVALUATE state")
                    self.state = State.EVALUATE
            
            # In the EVALUATE state, we find the best cluster to navigate towards
            case State.EVALUATE:
                if self.new_clusters:
                    self.evaluate()
                if self.goal is not None:
                    self.log("Going into SET_GOAL state")
                    self.state = State.SET_GOAL

            # In SET_GOAL, we set the navigation goal
            case State.SET_GOAL:
                if self.goal != None:
                    self.log(f"Navigating to goal!")
                    self.navigator.goToPose(self.goal)
                    self.state = State.NAVIGATE

            # In NAVIGATE we check for close items that we should pick up
            case State.NAVIGATE:
                # If there is a close item and there is no robot nearby, go into PICKUP state
                if self.get_closest_item(NAVIGATE_CLOSE_ITEM_THRESHOLD) is not None \
                        and not any(r.size > ROBOT_DETECTION_SIZE_THRESHOLD and math.fabs(r.x) < ROBOT_DETECTION_ANGLE_THRESHOLD for r in self.robots):
                    self.log("Going into PICKUP state")
                    self.navigator.cancelTask()
                    self.state = State.PICKUP

                # If the goal has finished without finding a close item, then the robot spins in place to find one of the items that SHOULD now be nearby
                elif self.navigator.isTaskComplete():
                    msg = Twist()
                    msg.angular.z = -0.8
                    self.cmd_vel_publisher.publish(msg)


            # In PICKUP state, we manually set the velocities of the robot to make it run into the closest object
            case State.PICKUP:
                # If there is another robot going for this cluster, go back to SET_GOAL and rely on nav2 to avoid collisions
                if any(r.size > ROBOT_DETECTION_SIZE_THRESHOLD and math.fabs(r.x) < ROBOT_DETECTION_ANGLE_THRESHOLD for r in self.robots):
                    self.state = State.SET_GOAL
                else:
                    msg = Twist()
                    # Get the closest item, which should not be None in this state
                    closest_item = self.get_closest_item(CLOSE_ITEM_THRESHOLD)

                    # If it is None, then we are too close to it so we must just move forward a bit
                    if closest_item is None:
                        msg.linear.x = 0.5

                    # Otherwise we rotate and move towards it
                    elif math.fabs(closest_item.x) > 25:
                        msg.linear.x = 0.1 # This stops the robot from getting stuck on choosing between 2 equally close objects
                        msg.angular.z = closest_item.x / 320.0 * 0.8
                    else:
                        msg.linear.x = 0.7
                    
                    # Publish the Twist message
                    self.cmd_vel_publisher.publish(msg)

            # In the return state, we check if the item was dropped of and go into FACE_ARENA when it has
            case State.RETURN:
                if not self.has_item():
                    self.log("Going into FACE_ARENA state")
                    self.navigator.cancelTask()
                    self.state = State.FACE_ARENA
            
            # In the FACE_ARENA state we rotate until we face the items again, and we go back into EVALUATE when done
            case State.FACE_ARENA:
                msg = Twist()
                if math.fabs(self.yaw) < 0.1:
                    self.log("Going into EVALUTAE state")
                    self.state = State.EVALUATE
                else:
                    msg.angular.z = -1.0
                self.cmd_vel_publisher.publish(msg)


      
    ## Helper functions ###
    def send_request(self, client, request):
        """
        Sends a request to a client

        @param client: The client to call
        @param request: The body of the request
        """
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        return future.result()
    
    def log(self, text):
        """
        Log with the name of the robot
        """
        self.get_logger().info(f"[{self.get_namespace()[1:]}]: {text}")
    
    ## Node destruction
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