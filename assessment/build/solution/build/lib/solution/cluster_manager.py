# Python packages
import sys
import math
import itertools

# ROS2 packages
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.signals import SignalHandlerOptions

# Solution Dependencies
from solution_interfaces.msg import WorldItem
from solution_interfaces.srv import GetClusters



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

        self.cluster_srv = self.create_service(GetClusters, '/clusters', self.get_clusters_callback)

    def world_items_callback(self, cluster):
        colour = cluster.colour
        if len(self.clusters[colour]) < 2:
            self.clusters[colour].append(cluster)
        else:
            if self.euclidean_distance(self.clusters[colour][0], cluster):
                self.clusters[colour][1] = cluster


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