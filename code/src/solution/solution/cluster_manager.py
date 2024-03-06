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
from solution_interfaces.msg import WorldItem, Clusters

class ClusterManager(Node):

    def __init__(self):
        super().__init__('cluster_manager')
        self.clusters = {
            'RED': [],
            'GREEN': [],
            'BLUE': [],
        }

        ## SUBSCRIBERS ##
        self.world_item_subscriber = self.create_subscription(
            WorldItem,
            "/world_items",
            self.world_items_callback,
            10)
        
        ## PUBLISHERS ##
        self.marker_publisher = self.create_publisher(MarkerArray, '/clusters_markers', 10) # Publishes a marker for rviz to use
        self.clusters_publisher = self.create_publisher(Clusters, '/clusters', 10) # Publishes the cluster locations for the robots to use


    ### Callbacks ###
    def world_items_callback(self, world_item):
        """
        This callback checks weather any of the new items detected by the robots can be from a new cluster
        """

        colour = world_item.colour
        # If there are less than 2 clusters of this color, then immediatly create a new cluster
        if len(self.clusters[colour]) < 2:
            self.clusters[colour].append(world_item)

        # Replace the second one only if the new item is further than the first cluster
        elif self.euclidean_distance(self.clusters[colour][0], world_item) > \
             self.euclidean_distance(self.clusters[colour][0], self.clusters[colour][1]) + 0.01:
                self.clusters[colour][1] = world_item
        
        # Otherwise there is nothing to do
        else:
            return
        
        # If this is called then an update to the clusters must be made
        self.create_markers_for_clusters()
    

    ### Cluster handling ###
    def create_markers_for_clusters(self):
        """
        This function iterates through all the clusters found in self.clusters and publishes them to topics
        """

        # Each marker must have a unique id
        id = 0

        marker_array = MarkerArray()
        clusters = Clusters()

        # Compact all clusters in one lise, irrespective of colour
        clusters.clusters = []
        for sublist in self.clusters.values():
            clusters.clusters.extend(sublist)

        # Iterate through all the clusters and add them to the marker array
        for item in clusters.clusters:
            self.log(f"Marking {item}")
            marker_array.markers.append(self.mark_cluster(id, item))
            id += 1
        
        # Publish the array to the marker topic for rviz
        self.marker_publisher.publish(marker_array)

        # Publish the clusters to the cluster topic for the robots to use
        self.clusters_publisher.publish(clusters)   

    def mark_cluster(self, id, item : WorldItem):
        """
        This function takes an world item object and transforms it into a marker that rviz can use

        @param id: id of the marker
        @param item: WorldItem object to be wrapped
        """
        marker = Marker()
        marker.header.frame_id = "/map"
        marker.type = 2
        marker.id = id
        # Set the scale of the marker
        marker.scale.x = 0.25
        marker.scale.y = 0.25
        marker.scale.z = 0.25
        # Set the color
        if item.colour == "GREEN":
            marker.color.g = 1.0
        if item.colour == "RED":
            marker.color.r = 1.0
        if item.colour == "BLUE":
            marker.color.b = 1.0
        marker.color.a = 1.0
        # Set the pose of the marker
        marker.pose.position.x = item.x
        marker.pose.position.y = item.y
        marker.pose.position.z = 0.0
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0

        return marker             

    
    ### Helper functions ###
    def euclidean_distance(self, c1: WorldItem, c2: WorldItem):
        """
        Returns the euclidean distance between two items
        """
        return math.sqrt((c1.x - c2.x)**2 + (c1.y - c2.y)**2)
    
    def log(self, text):
        self.get_logger().info(f"[{self.get_namespace()}]: {text}")


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