# Python packages
import sys
import os
from ament_index_python.packages import get_package_share_directory
import yaml
import numpy as np

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.signals import SignalHandlerOptions
from nav2_simple_commander.robot_navigator import BasicNavigator
from nav2_simple_commander.costmap_2d import PyCostmap2D
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from nav_msgs.srv import GetMap
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import OccupancyGrid, Odometry


# Solution Dependencies
from solution_interfaces.msg import Clusters, WorldItem
from solution_interfaces.srv import InitialPose

class NavManager(Node):

    def __init__(self):
        super().__init__('nav_manager')
        self.navigator = BasicNavigator()
        self.new_clusters = False # Records wether new clusters were detected since last reevaluation
        self.clusters = []

        # Get initial poses
        yaml_path = os.path.join(get_package_share_directory('assessment'), 'config', 'initial_poses.yaml')
        with open(yaml_path, 'r') as f:
            configuration = yaml.safe_load(f)
        self.initial_poses = configuration[3]

        # Service clients
        self.map_cli = self.create_client(GetMap, '/robot1/map_server/map')
        while not self.map_cli.wait_for_service(timeout_sec=1.0):
            self.log('Map service not available, waiting again...')
        self.map_req = GetMap.Request()
        self.log("Connected to map service")

        # Get the costmap object
        response = self.send_request(self.map_cli, self.map_req)
        self.occupancy_grid = response.map
        self.map = PyCostmap2D(self.occupancy_grid)
        self.empty_map = PyCostmap2D(self.occupancy_grid)
        self.log("Obtained map object")


        # Services
        self.initial_pose_srv = self.create_service(InitialPose, '/initial_pose', self.get_initial_poses)

        ## SUBSCRIPTIONS ##
        self.clusters_subscriber = self.create_subscription(
            Clusters,
            "/clusters",
            self.clusters_callback,
            10)
        
        # self.red_map_subscriber = self.create_subscription(
        #     OccupancyGrid,
        #     "/RED",
        #     self.red_map_callback,
        #     10)

        # self.green_map_subscriber = self.create_subscription(
        #     OccupancyGrid,
        #     "/GREEN",
        #     self.green_map_callback,
        #     10)
        
        # self.blue_map_subscriber = self.create_subscription(
        #     OccupancyGrid,
        #     "/BLUE",
        #     self.blue_map_callback,
        #     10)
        
    def send_request(self, client, request):
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        return future.result()
        
    def log(self, text):
        self.get_logger().info(f"[nav_manager]: {text}")
    
    def clusters_callback(self, msg):
        self.clusters = msg.clusters
    

    def get_initial_poses(self, request, response):
        response.x = self.initial_poses[request.robot_id]['x']
        response.y = self.initial_poses[request.robot_id]['y']
        return response


    # def evaluate_path(self, path, colour):
    #     self.updateMap(colour)
    #     match colour:
    #         case "RED":
    #             value = 5
    #         case "GREEN":
    #             value = 10
    #         case "BLUE":
    #             value = 15
        
    #     distance = 0
    #     for i in range(len(path.poses) - 1):
    #         position_a_x = path.poses[i].pose.position.x
    #         position_b_x = path.poses[i+1].pose.position.x
    #         position_a_y = path.poses[i].pose.position.y
    #         position_b_y = path.poses[i+1].pose.position.y

    #         distance += np.sqrt(np.power((position_b_x - position_a_x), 2) + np.power((position_b_y- position_a_y), 2))
        
    #     return value / distance

    
    # def evaluate(self):
    #     if self.clusters == []:
    #         return

    #     best_value = None
    #     best_cluster = None
    #     best_goal = None
    #     # iterate through the clusters to find the best one
        
    #     for cluster in self.clusters:
    #         goal_pose = PoseStamped()
    #         goal_pose.header.frame_id = 'map'
    #         goal_pose.header.stamp = self.get_clock().now().to_msg()
    #         goal_pose.pose.position.x = cluster.x
    #         goal_pose.pose.position.y = cluster.y
    #         goal_pose.pose.orientation.z = 0.0
    #         goal_pose.pose.orientation.w = 1.0

    #         # best_cluster = cluster
    #         # best_goal = goal_pose
    #         # break

    #         path = self.navigator.getPath(self.initial_pose, goal_pose)
    #         value = self.evaluate_path(path, cluster.colour)
    #         if best_value is None or value > best_value:
    #             best_value = value
    #             best_cluster = cluster
    #             best_goal = goal_pose

    #     self.new_clusters = False
    
    #     self.log(f"New GOAL selected!")
    #     self.goal = best_goal
    #     self.colour = best_cluster.colour
    #     self.updateMap(self.colour)



def main(args=None):
    rclpy.init(args=args, signal_handler_options = SignalHandlerOptions.NO)

    node = NavManager()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()