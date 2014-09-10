#!/bin/bash
source ~/fuerte_workspace/setup.bash
export ROS_PACKAGE_PATH=~/workspace/PoCRCC8/controller/rosCanonicalController:~/fuerte_workspace/:$ROS_PACKAGE_PATH
export LD_LIBRARY_PATH=/usr/local/rcslib/lib:$LD_LIBRARY_PATH
roslaunch usarsim_inf usarsimRobot.launch coordinate_change:=True &
sleep 5;
roslaunch KR60_arm_navigation KR60_arm_navigation.launch &
