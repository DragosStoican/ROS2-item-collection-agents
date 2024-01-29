import os
from ament_index_python.packages import get_package_share_directory
import yaml

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node, SetParameter

def generate_launch_description():
    package_name = 'solution'
    num_robots = 3
    rviz_config = PathJoinSubstitution([FindPackageShare('assessment'), 'rviz', 'namespaced_nav2.rviz'])
    map = PathJoinSubstitution([FindPackageShare('assessment'), 'maps', 'assessment_world.yaml'])
    # params = PathJoinSubstitution([FindPackageShare('assessment'), 'params', 'nav2_params_namespaced.yaml'])
    params = PathJoinSubstitution([FindPackageShare(package_name), 'params', 'custom_nav2_params_namespaced.yaml'])

    yaml_path = os.path.join(get_package_share_directory('assessment'), 'config', 'initial_poses.yaml')

    with open(yaml_path, 'r') as f:
        configuration = yaml.safe_load(f)

    initial_poses = configuration[num_robots]

    assessment_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare('assessment'),
                'launch',
                'assessment_launch.py'
                ])
        ),
        launch_arguments={'num_robots': str(num_robots),
                          'visualise_sensors': 'false',
                          'odometry_source': 'WORLD',
                          'sensor_noise': 'false',
                          'use_rviz': 'true',
                          'rviz_config': rviz_config,
                          'obstacles': 'true',
                          'item_manager': 'true',
                          'random_seed': '0',
                          'use_nav2': 'True',
                          'map': map,
                          'params': params,
                          # 'extra_gazebo_args': '--verbose',
                          }.items()
    )

    robot_controller_cmd = []

    for robot_number in range(1, num_robots + 1):

        robot_name = 'robot' + str(robot_number)

        node = Node(
            package='solution',
            executable='robot_controller',
            output='screen',
            namespace=robot_name,
            parameters=[initial_poses[robot_name]])

        robot_controller_cmd.append(node)


    start_cluster_manager = Node(
        package='solution',
        executable='cluster_manager',
        output='screen',
    )

    start_nav_manager = Node(
        package='solution',
        executable='nav_manager',
        output='screen',
    )

    start_world_item_manager = Node(
        package='solution',
        executable='world_item_manager',
        output='screen',
    )

    ld = LaunchDescription()

    ld.add_action(SetParameter(name='use_sim_time', value=True))

    ld.add_action(assessment_cmd)

    ld.add_action(start_cluster_manager)

    ld.add_action(start_world_item_manager)

    ld.add_action(start_nav_manager)

    ld.add_action(TimerAction(period=8.0, actions=robot_controller_cmd))

    return ld
