# # Python packages
# import sys
# import os
# from ament_index_python.packages import get_package_share_directory
# import yaml

# # ROS2 packages
# import rclpy
# from rclpy.node import Node
# from rclpy.executors import ExternalShutdownException
# from rclpy.signals import SignalHandlerOptions

# # Solution Dependencies
# from solution_interfaces.srv import InitialPose

# class RobotManager(Node):

#     def __init__(self):
#         super().__init__('robot_manager')

#         # Get initial poses
#         yaml_path = os.path.join(get_package_share_directory('assessment'), 'config', 'initial_poses.yaml')
#         with open(yaml_path, 'r') as f:
#             configuration = yaml.safe_load(f)
#         self.initial_poses = configuration[3]


#         # Services
#         self.initial_pose_srv = self.create_service(InitialPose, '/initial_pose', self.get_initial_poses)
    

#     def get_initial_poses(self, request, response):
#         self.get_logger().info("Returning response")
#         response.x = self.initial_poses[request.robot_id]['x']
#         response.y = self.initial_poses[request.robot_id]['y']
#         return response


# def main(args=None):
#     rclpy.init(args=args, signal_handler_options = SignalHandlerOptions.NO)

#     node = RobotManager()

#     try:
#         rclpy.spin(node)
#     except KeyboardInterrupt:
#         pass
#     except ExternalShutdownException:
#         sys.exit(1)
#     finally:
#         node.destroy_node()
#         rclpy.try_shutdown()


# if __name__ == '__main__':
#     main()