#!/bin/bash

xhost +local:docker
docker start ros2-assessment
#source /root/env_ros_openai/bin/activate
docker exec -it ros2-assessment bash
