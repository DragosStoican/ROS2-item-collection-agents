import sys
from enum import Enum

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException

from assessment_interfaces.msg import ItemList
from geometry_msgs.msg import Twist, Pose
from std_msgs.msg import String
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from nav2_simple_commander.costmap_2d import PyCostmap2D
from nav_msgs.msg import OccupancyGrid
from nav_msgs.srv import GetMap
from nav2_simple_commander.costmap_2d import PyCostmap2D

class State(Enum):
    SEARCH = 0 # Search for an item to collect
    NAVIGATE = 1 # Navigate to a point where there are items to collect
    PICKUP = 2 # Drive into an object in sight
    RETURN = 3 # Return home to drop off item
    EVALUATE = 4 # Reevaluate weather there is a better cluster to collect from

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        self.declare_parameter('colour', '')

        self.state = State.SEARCH
        

        # Costmap
        self.map = None
        self.cli = self.create_client(GetMap, 'map_server/map')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = GetMap.Request()
        response = self.send_request()
        self.map = response.map
        # self.map = response


        # Navigator        
        self.navigator = BasicNavigator()
        self.items = []

        # self.declare_parameter('x', 0.0)
        # self.declare_parameter('y', 0.0)
        # self.declare_parameter('yaw', 0.0)

        # self.initial_x = self.get_parameter('x').get_parameter_value().double_value
        # self.initial_y = self.get_parameter('y').get_parameter_value().double_value
        # self.initial_yaw = self.get_parameter('yaw').get_parameter_value().double_value

        self.item_subscriber = self.create_subscription(
            ItemList,
            'items',
            self.item_callback,
            10)
        
        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10)

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    def send_request(self):
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


    def item_callback(self, msg):
        self.items = msg.data

    def control_loop(self):
        # # colour = self.get_parameter('colour').get_parameter_value().string_value
        match self.state:
            case State.SEARCH:
                self.get_logger().info("My map is: " + (str(type(self.map))))
                # self.get_logger().info(self.get_namespace() + " detected items in front " + (str(self.items)))

        #         if len(self.items) > 0:
        #             # Check if we are only lookig at one cluster
        #             if all(item.colour == self.items[0].colour for item in self.items):
        #                 colour = self.items[0].colour
        #                 self.get_logger().info(self.get_namespace() + " changing colour to " + colour)
        #                 new_colour = rclpy.parameter.Parameter('colour', rclpy.Parameter.Type.STRING, colour)
        #                 self.set_parameters([new_colour])
        #             else:
        #                 pass
        #                 # TODO: What if there are multiple types of items in view?
        #             self.get_logger().info(self.get_namespace() + " going into PICKUP state")
        #             self.state = State.PICKUP
        #         else:
        #             pass
        #             # TODO: What if there are no items?
                        

    def destroy_node(self):
        super().destroy_node()


def main(args=None):

    rclpy.init(args = args, signal_handler_options = SignalHandlerOptions.NO)

    node = RobotController()

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