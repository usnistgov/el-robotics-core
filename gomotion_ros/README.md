This package is an interface between a running Go Motion controller and a ROS JointState topic.

In RViz, you need to set the "Fixed Frame" to be "base_link", and
"Add" a "Rpbpt Model". Save this to something like myrobot.rviz and
pass this as an arg to the rviz node launch.

Demo January 31 2017
--------------------
1. Ran two gomotion controllers:

cd /usr/local/proctor/github/frederickproctor/gomotion
bin/gorun -i etc/fanuc-lrmate-200id.ini

cd /usr/local/proctor/github/frederickproctor/gomotion
bin/gorun -i etc/motoman-sia20f.ini

2. Ran two gomotion_ros programs:

cd /usr/local/proctor/gomotion_ros_ws
. devel/setup.bash
roslaunch gomotion_ros gomotion_ros.launch ns:=fanuc inifile:=/usr/local/proctor/github/frederickproctor/gomotion/etc/fanuc-lrmate-200id.ini

cd /usr/local/proctor/gomotion_ros_ws
. devel/setup.bash
roslaunch gomotion_ros gomotion_ros.launch ns:=motoman inifile:=/usr/local/proctor/github/frederickproctor/gomotion/etc/motoman-sia20f.ini

3. Ran two RViz applications:

cd /usr/local/proctor/gomotion_ros_ws
. devel/setup.bash
roslaunch gomotion_ros rviz.launch robot_description:=/usr/local/proctor/github/ros-industrial/fanuc_experimental/fanuc_lrmate200id_support/urdf/lrmate200id.urdf source_list:=[joint_states] ns:=fanuc

cd /usr/local/proctor/gomotion_ros_ws
. devel/setup.bash
roslaunch gomotion_ros rviz.launch robot_description:=/usr/local/proctor/github/ros-industrial/motoman/motoman_sia20d_support/urdf/sia20d.urdf source_list:=[joint_states] ns:=motoman

> rosparam list
/fanuc/joint_state_publisher/blarf
/fanuc/joint_state_publisher/source_list
/fanuc/joint_state_publisher/use_gui
/fanuc/robot_description
/motoman/joint_state_publisher/source_list
/motoman/joint_state_publisher/use_gui
/motoman/robot_description
/rosdistro
/roslaunch/uris/host_bibendum__37823
/roslaunch/uris/host_bibendum__38463
/roslaunch/uris/host_bibendum__42458
/roslaunch/uris/host_bibendum__44888
/roslaunch/uris/host_bibendum__48272
/roslaunch/uris/host_bibendum__49504
/roslaunch/uris/host_bibendum__54329
/roslaunch/uris/host_bibendum__55715
/rosversion
/run_id

> rostopic list
/clicked_point
/fanuc/joint_states
/initialpose
/motoman/joint_states
/move_base_simple/goal
/rosout
/rosout_agg
/tf
/tf_static
