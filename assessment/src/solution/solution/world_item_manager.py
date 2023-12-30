# Python packages
import sys
from ament_index_python.packages import get_package_share_directory
import numpy as np
from array import array
import copy

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.signals import SignalHandlerOptions
from nav2_simple_commander.costmap_2d import PyCostmap2D
from nav_msgs.srv import GetMap
from nav_msgs.msg import OccupancyGrid


# Solution Dependencies
from solution_interfaces.msg import WorldItem

class Map:
    def __init__(self, colour, occupancy_grid, node:Node):
        self.colour = colour
        self.items = []
        self.occupancy_grid = copy.deepcopy(occupancy_grid)
        self.map = PyCostmap2D(occupancy_grid)
        self.map_publisher_1 = node.create_publisher(OccupancyGrid, f'/robot1/{self.colour}', 10)
        self.map_publisher_2 = node.create_publisher(OccupancyGrid, f'/robot2/{self.colour}', 10)
        self.map_publisher_3 = node.create_publisher(OccupancyGrid, f'/robot3/{self.colour}', 10)
    
    def add_item(self, x, y):
        self.items.append((x, y))
        self.map.setCost(x, y, 100)
    
    def has_item(self, x, y):
        for item in self.items:
            if x == item[0] and y == item[1]:
                return True
        return False
    
    def update(self):
        new_grid = array('b', self.map.costmap)
        self.occupancy_grid.data = new_grid
        self.map_publisher_1.publish(self.occupancy_grid)
        self.map_publisher_2.publish(self.occupancy_grid)
        self.map_publisher_3.publish(self.occupancy_grid)
        

class WorldItemManager(Node):

    def __init__(self):
        super().__init__('world_item_manager')

        # Service clients
        self.map_cli = self.create_client(GetMap, '/robot1/map_server/map')
        while not self.map_cli.wait_for_service(timeout_sec=1.0):
            self.log('Map service not available, waiting again...')
        self.map_req = GetMap.Request()
        self.log("Connected to map service")

        # Get the costmap object
        response = self.send_request(self.map_cli, self.map_req)
        self.occupancy_grid = response.map
        self.maps = {
            'RED': Map("RED", self.occupancy_grid, self),
            'GREEN': Map("GREEN", self.occupancy_grid, self),
            'BLUE': Map("BLUE", self.occupancy_grid, self),
        }
        self.log("Obtained map object")
        self.worldToMap = self.maps["RED"].map.worldToMap

        ## SUBSCRIPTIONS ##
        self.world_item_subscriber = self.create_subscription(
            WorldItem,
            "/world_items",
            self.world_items_callback,
            10)
        
    def send_request(self, client, request):
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        return future.result()
        
    def log(self, text):
        self.get_logger().info(f"[world_item_manager]: {text}")

    def item_on_map(self, colour, x, y) -> bool:
        """
        Check weather or not item of colour `colour` at map coordinates [x, y] is on the robot's costmap
        """
        for item in self.all_items:
            if item[0] == x and item[1] == y:
                return True
        return False  
    
    def world_items_callback(self, msg):
        match msg.colour:
            case "RED":
                to_update = [self.maps["GREEN"], self.maps["BLUE"]]
            case "GREEN":
                to_update = [self.maps["RED"], self.maps["BLUE"]]
            case "BLUE":
                to_update = [self.maps["RED"], self.maps["GREEN"]]
        x_map, y_map = self.worldToMap(msg.x, msg.y)
        for map in to_update:
            if not map.has_item(x_map, y_map):
                map.add_item(x_map, y_map)
                map.update()


def main(args=None):
    rclpy.init(args=args, signal_handler_options = SignalHandlerOptions.NO)

    node = WorldItemManager()

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