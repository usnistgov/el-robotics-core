#!/bin/bash
source /home/michalos/catkin_ws/devel/setup.bash
#roslaunch fanucdemo jointgui.launch
#rosrun joint_states_listener joint_states_listener.py
rosrun nist_fanuc joint_states_listener.py
sleep 1000
