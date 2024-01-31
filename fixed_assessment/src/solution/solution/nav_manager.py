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

        # Services
        self.initial_pose_srv = self.create_service(InitialPose, '/initial_pose', self.get_initial_poses)

        
    def send_request(self, client, request):
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        return future.result()
    

    def get_initial_poses(self, request, response):
        response.x = self.initial_poses[request.robot_id]['x']
        response.y = self.initial_poses[request.robot_id]['y']
        return response
    

    def log(self, text):
        self.get_logger().info(f"[nav_manager]: {text}")



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