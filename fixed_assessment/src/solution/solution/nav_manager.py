# Python packages
import sys
import os
from ament_index_python.packages import get_package_share_directory
import yaml

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.signals import SignalHandlerOptions
from nav_msgs.srv import GetMap


# Solution Dependencies
from solution_interfaces.srv import InitialPose

NUM_ROBOTS = 3

class NavManager(Node):

    def __init__(self):
        super().__init__('nav_manager')

        # Get initial poses
        yaml_path = os.path.join(get_package_share_directory('assessment'), 'config', 'initial_poses.yaml')
        with open(yaml_path, 'r') as f:
            configuration = yaml.safe_load(f)
        self.initial_poses = configuration[NUM_ROBOTS]

        ### Service clients ###
        self.map_cli = self.create_client(GetMap, '/robot1/map_server/map')
        while not self.map_cli.wait_for_service(timeout_sec=1.0):
            self.log('Map service not available, waiting again...')
        self.map_req = GetMap.Request()
        self.log("Connected to map service")

        ### Services ###
        self.initial_pose_srv = self.create_service(InitialPose, '/initial_pose', self.get_initial_poses)
    

    ### Services ###
    def get_initial_poses(self, request, response):
        """
        This services takes in the robot name and returns its starting pose

        @param request: Request defined in InitialPose.srv
        @param respose: Response defined in InitialPose.srv
        """
        response.x = self.initial_poses[request.robot_id]['x']
        response.y = self.initial_poses[request.robot_id]['y']
        return response
    

    ### Helper functions ###
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