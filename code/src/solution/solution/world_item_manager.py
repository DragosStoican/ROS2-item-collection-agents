# Python packages
import sys
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


# Clear parameters for when an item is picked up
CLEAR_RANGE = 6
DX = [i for i in range(-CLEAR_RANGE, CLEAR_RANGE)]
DY = [i for i in range(-CLEAR_RANGE, CLEAR_RANGE)]

class Map:
    """
    This is a helper class that wraps a occupancy_grid object with usefull functions from the PyCostmap2D object
    """
    def __init__(self, colour, occupancy_grid, node:Node):
        self.colour = colour
        self.items = []
        self.occupancy_grid = copy.deepcopy(occupancy_grid)
        self.map = PyCostmap2D(occupancy_grid)
        self.map_publisher = node.create_publisher(OccupancyGrid, f'/{self.colour}', 10) # Publishes the map to its own topic
    
    def add_item(self, x, y):
        """
        Adds item at map location [x ,y] to the grid
        """
        self.items.append((x, y))
        self.map.setCost(x, y, 100)

    def remove_item(self, x, y):
        """
        Removes item at map location [x, y] (and it's nearby neighbours) from the grid
        """
        for i in DX:
            for j in DY:
                x_update = x + i
                y_update = y + j
                if self.has_item(x_update, y_update):
                    self.items.remove((x_update, y_update))
                    self.map.setCost(x_update, y_update, 0)

    
    def has_item(self, x, y):
        """
        Returns true if there is an item at map location [x, y]
        """
        for item in self.items:
            if x == item[0] and y == item[1]:
                return True
        return False
    
    def update(self):
        """
        Publishes to the relevant topic the current occupancy_grid
        """
        new_grid = array('b', self.map.costmap)
        self.occupancy_grid.data = new_grid
        self.map_publisher.publish(self.occupancy_grid)
        

class WorldItemManager(Node):

    def __init__(self):
        super().__init__('world_item_manager')

        ### Service clients ###
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
        self.worldToMap = self.maps["RED"].map.worldToMap # This is a shortcut for transforming world coordinates to map coordinates

        ## SUBSCRIPTIONS ##
        self.world_item_subscriber = self.create_subscription( # World items to add to the maps
            WorldItem,
            "/world_items",
            self.world_items_callback,
            10)
        
        self.pickedup_item_subscriber = self.create_subscription( # World items that were picked up
            WorldItem,
            "/pickedup_items",
            self.pickedup_item_callback,
            10)

    ### Callbacks ###    
    def world_items_callback(self, msg):
        """
        This callback computes which maps need to be updated then adds the item from the message to the relevant maps
        """
        match msg.colour:
            case "RED":
                to_update = [self.maps["GREEN"], self.maps["BLUE"]]
            case "GREEN":
                to_update = [self.maps["RED"], self.maps["BLUE"]]
            case "BLUE":
                to_update = [self.maps["RED"], self.maps["GREEN"]]
        
        # Transform to map coordinates
        x_map, y_map = self.worldToMap(msg.x, msg.y)

        # Update the maps
        for map in to_update:
            if not map.has_item(x_map, y_map):
                map.add_item(x_map, y_map)
                map.update()
    
    def pickedup_item_callback(self, msg):
        """
        This callback computes which maps need to be updated and removes items based on what item was picked up
        """
        self.log("Processing pickedup item")
        match msg.colour:
            case "RED":
                to_update = [self.maps["GREEN"], self.maps["BLUE"]]
            case "GREEN":
                to_update = [self.maps["RED"], self.maps["BLUE"]]
            case "BLUE":
                to_update = [self.maps["RED"], self.maps["GREEN"]]

        # Transform to map coordinates
        x_map, y_map = self.worldToMap(msg.x, msg.y)

        # Update the maps
        for map in to_update:
            self.log(f"Removing item at {x_map} {y_map}")
            map.remove_item(x_map, y_map)
            map.update()



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
        self.get_logger().info(f"[world_item_manager]: {text}")


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