#!/bin/bash
roslaunch usarsim_inf usarsimRobot.launch coordinate_change:=True hostname:=sbalakirsky-e64&
#roslaunch usarsim_inf usarsimKR60.sbalakirsky.launch &
#roslaunch usarsim_inf usarsimRobot.launch hostname:=sbalakirsky-e64&
sleep 5;
roslaunch KR60_arm_navigation KR60_arm_navigation.launch &
sleep 5;
rosrun usarsim_tools collision_map.py 

