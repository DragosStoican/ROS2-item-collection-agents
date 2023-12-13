import sys
from enum import Enum

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException
from rclpy.qos import QoSProfile, QoSDurabilityPolicy

from assessment_interfaces.msg import ItemList
from geometry_msgs.msg import Twist, Pose
from std_msgs.msg import String
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from nav2_simple_commander.costmap_2d import PyCostmap2D
from nav_msgs.msg import OccupancyGrid
from nav_msgs.srv import GetMap
from array import *

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
        self.test = True
        

        # Costmap
        self.map = None
        self.cli = self.create_client(GetMap, 'map_server/map')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = GetMap.Request()
        response = self.send_request()
        self.occupancy_grid = response.map
        self.map = PyCostmap2D(self.occupancy_grid)
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
        qos = QoSProfile(durability = QoSDurabilityPolicy.TRANSIENT_LOCAL,
                         depth = 10)
        self.occupancy_grid_punlisher = self.create_publisher(OccupancyGrid, 'map', qos)

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    def updateMap(self):
        self.get_logger().info("Test: " + str(self.occupancy_grid.data.typecode))

        # while self.occupancy_grid.data.itemsize > 0:
        #     self.occupancy_grid.data.pop()
        # self.get_logger().info("Test: " + str(self.occupancy_grid.data.itemsize))
        # self.occupancy_grid.data.fromlist(self.map.costmap.tolist())
        self.occupancy_grid.data = array('b', self.map.costmap)
        # self.get_logger().info("Test: " + str(type(self.occupancy_grid.data)))
        self.get_logger().info("Puiblishing to /robot1/map")
        self.occupancy_grid_punlisher.publish(self.occupancy_grid)

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
                # self.get_logger().info("My map is: " + (str(self.map.costmap))) #OccupancyGrid
                # self.get_logger().info("Resolution: " + str(self.map.resolution) + "\n" +
                #                        "Postion: " + str(self.map.getOriginX()) + " " + str(self.map.origin_y) + "\n" +
                #                        "Width: " + str(self.map.getSizeInCellsX()) + "\n" +
                #                        "Height: " + str(self.map.getSizeInCellsY()) + "\n" +
                #                        "Width_meters: " + str(self.map.getSizeInMetersX()) + "\n" +
                #                        "Height_meters: " + str(self.map.getSizeInMetersY())
                                        # )
                if self.test:
                    self.get_logger().info("Test: " + str(type(self.occupancy_grid.data)))
                    self.get_logger().info("Max cost is: " + (str(self.map.costmap.max())))
                    max = self.map.costmap.max()
                    x, y = self.map.worldToMap(-2, 0)
                    self.get_logger().info("Old cost is: " + (str(self.map.getCostXY(x, y))))
                    self.map.setCost(x, y, max)
                    self.get_logger().info("New cost is: " + (str(self.map.getCostXY(x, y))))
                    self.updateMap()
                    
                    self.test = False
                else:
                    self.get_logger().info("Hello!")
                                       

                                       
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