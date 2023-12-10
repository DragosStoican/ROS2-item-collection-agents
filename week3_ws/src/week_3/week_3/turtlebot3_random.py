import rclpy
from rclpy.node import Node

from rclpy.qos import QoSPresetProfiles, QoSProfile, QoSHistoryPolicy

from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from tf_transformations import euler_from_quaternion

from enum import Enum
import random
import time
import math

class State(Enum):
    FORWARD = 0
    TURNING = 1

class TurtleBot3FSM(Node):

    def __init__(self):
        super().__init__('turtlebot3_fsm')

        self.declare_parameter('turning', "counter")
        self.turning_type = str(self.get_parameter('turning').value)
        self.get_logger().info(f"Turning_type: {self.turning_type}")

        self.state = State.FORWARD
        self.counter = 0
        self.robot_pose_ = 0
        self._reset_random()

        ###############################################
        ## Initialise ROS publishers and subscribers ##
        ###############################################

        qos = QoSProfile(history = QoSHistoryPolicy.KEEP_LAST,
                         depth = 10)

        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)

        self.odom_sub_ = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            qos)
        self.odom_sub_  # prevent unused variable warning


        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)
    
    def odom_callback(self, msg):
        q = [msg.pose.pose.orientation.x,
             msg.pose.pose.orientation.y,
             msg.pose.pose.orientation.z,
             msg.pose.pose.orientation.w]
        
        (roll, pitch, yaw) = euler_from_quaternion(q)
        self.robot_pose_ = yaw

        self.get_logger().info(f"robot_pose_: {self.robot_pose_}")

    def _reset_random(self):
        self.forward = random.randint(1, 8)
        self.turning = random.uniform(0, 2)
        self.turning_direction = random.choice([-1, 1])
        self.get_logger().info(f"RANDOM_FORWARD: {self.forward}\n\
                                 RANDOM_TURNING: {self.turning}\n\
                                 RANDOM_TURNING_DIRECTION : {'LEFT' if self.turning_direction == 1 else 'RIGHT'}")


    def control_loop(self):

        match self.state:
            case State.FORWARD:
                msg = Twist()
                msg.linear.x = 0.3
                self.publisher.publish(msg)
                # self.get_logger().info(f"Forward: {msg}")
                if self.counter > self.forward * (1 / self.timer_period):
                    self.state = State.TURNING
                    self.counter = 0
                self.counter += 1
            case State.TURNING:
                msg = Twist()
                msg.angular.z = 1.5 * self.turning_direction
                self.publisher.publish(msg)
                # self.get_logger().info(f"Turning: {msg}")
                if self.turning_type == "counter":
                    if self.counter > self.turning * (1 / self.timer_period):
                        self.state = State.FORWARD
                        self.counter = 0
                        self._reset_random()
                    self.counter += 1
                elif self.turning_type == "wall-clock":
                    # self.get_logger().info(f"Turning: {msg}")
                    time.sleep(self.turning * 2)
                    self.state = State.FORWARD
                    self.counter = 0
                    self._reset_random()
                # elif self.turning_type == "angle":

            case _:
                pass

def main(args=None):
    rclpy.init(args=args)

    turtlebot3_fsm = TurtleBot3FSM()

    rclpy.spin(turtlebot3_fsm)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    turtlebot3_fsm.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()