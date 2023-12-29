# Python packages
import sys
import math
import itertools

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.signals import SignalHandlerOptions
from visualization_msgs.msg import Marker, MarkerArray

# Solution Dependencies
from solution_interfaces.msg import WorldItem
from solution_interfaces.srv import GetClusters

class ClusterManager(Node):

    def __init__(self):
        super().__init__('cluster_manager')
        self.marker_id = 0
        self.clusters = {
            'RED': [],
            'GREEN': [],
            'BLUE': [],
        }

        # Services
        self.cluster_srv = self.create_service(GetClusters, '/clusters', self.get_clusters_callback)

        ## SUBSCRIBERS ##
        self.world_item_subscriber = self.create_subscription(
            WorldItem,
            "/world_items",
            self.world_items_callback,
            10)
        
        ## PUBLISHERS ##
        self.marker_publisher = self.create_publisher(MarkerArray, '/clusters_markers', 10)

    
    def create_marker_array(self, id, colour, x, y):
        marker_array = MarkerArray()
        marker = Marker()
        marker.header.frame_id = "/map"
        # marker.header.stamp = self.get_clock().now()
        marker.type = 2
        marker.id = id
        # Set the scale of the marker
        marker.scale.x = 0.25
        marker.scale.y = 0.25
        marker.scale.z = 0.25
        # Set the color
        if colour == "GREEN":
            marker.color.g = 1.0
        if colour == "RED":
            marker.color.r = 1.0
        if colour == "BLUE":
            marker.color.b = 1.0
        marker.color.a = 1.0
        # Set the pose of the marker
        marker.pose.position.x = x
        marker.pose.position.y = y
        marker.pose.position.z = 0.0
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0

        marker_array.markers.append(marker)
        self.marker_publisher.publish(marker_array)
        

    def create_markers_for_clusters(self):
        id = 0
        for sublist in self.clusters.values():
            for item in sublist:
                self.create_marker_array(id, item.colour, item.x, item.y)
                id += 1


    def world_items_callback(self, world_item):
        colour = world_item.colour
        if len(self.clusters[colour]) < 2:
            self.clusters[colour].append(world_item)

        elif self.euclidean_distance(self.clusters[colour][0], world_item) > \
             self.euclidean_distance(self.clusters[colour][0], self.clusters[colour][1]):
                self.clusters[colour][1] = world_item
        else:
            return
        
        self.create_markers_for_clusters()
        

        
    def euclidean_distance(self, c1: WorldItem, c2: WorldItem):
        return math.sqrt((c1.x - c2.x)**2 + (c1.y - c2.y)**2)
    

    def get_clusters_callback(self, request, response):
        out = []
        for sublist in self.clusters.values():
            out.extend(sublist)
        response.clusters = out
        return response


def main(args=None):
    rclpy.init(args=args, signal_handler_options = SignalHandlerOptions.NO)

    node = ClusterManager()

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