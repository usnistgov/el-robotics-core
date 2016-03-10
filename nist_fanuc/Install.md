
This package assume you have installed descartes, ros industrial core and fanuc experimental  packages.

To catkin_make the nist_fanuc package you will need to install:
1) xerces xml  ( for the library and include files).
2) Codesynthesis (for the include files).
3) KDL inverse kinematics were used instead of ikfast. Neither great, and exhibited 
arm swings.
4) If you ever get catkin_make to work, you can run the script runrvizdemo.bash to launch rviz with 

Installing Xerces c with Ubuntu
-----------------------------
https://www.daniweb.com/hardware-and-software/linux-and-unix/threads/409769/ubuntu-11-10-xerces-c 
As far as I'm aware libxerces is the same as pretty much any other library in Debian based systems. It should be available in the repositories (the exact version will depend on which version of Ubuntu you're running).

You can use apt-get to install the packages for the library and the dev files.
Then to use them in your C/C++ programs you simply #include the appropriate headers and link with the library when compiling/linking.

sudo apt-get update
apt-cache search libxerces
sudo apt-get install libxerces-c3.1 libxerces-c-dev

Need include file path CMakeLists.txt:
  include_directories(/usr/include/xercesc)

Link library in  CMakeLists.txt:
  link_directories(/usr/lib/x86_64-linux-gnu/)

Need to link against libxerces.a in CMakeLists.txt:
  link_directories(/usr/lib/x86_64-linux-gnu/)

Installing CodeSynthesis XSD
---------------------------------------
http://www.codesynthesis.com/products/xsd/download.xhtml
Chose the linux deb install file that matches you computer (below 64 bit amd).
Download xsd_4.0.0-1_amd64.deb and it will say open with Ubuntu Software Center
Click to install, authenticate and add /usr/include/xsd/cxx/xml as include path.

Need include file path in CMakeLists.txt:
include_directories(/usr/include/xsd/cxx/xml)


How the fanuc lrmate 200id IKFast kinematics plug in is installed
------------------------------------------
http://sdk.rethinkrobotics.com/wiki/MoveIt_Tutorial

rosed <myrobot_name>_moveit_config/config/kinematics.yaml

Edit these parts:

<planning_group_name>:
  kinematics_solver: <moveit_ik_plugin_pkg>/IKFastKinematicsPlugin
-OR-
  kinematics_solver: kdl_kinematics_plugin/KDLKinematicsPlugin

IBID: /home/michalos/catkin_ws/src/fanuc_experimental/fanuc_lrmate200ib3l_moveit_config/config/kinematics.yaml
manipulator:
  kinematics_solver: fanuc_lrmate200id_manipulator_kinematics/IKFastKinematicsPlugin
  kinematics_solver_attempts: 3
  kinematics_solver_search_resolution: 0.005
  kinematics_solver_timeout: 0.005

You will now need to recompile and install the IKFast plugins.
   catkin_make
   catkin_make install --pkg fanuc_lrmate200ib3l_manipulator_kinematics_plugin

michalos@rufous:~/catkin_ws$ rospack list
....
fanuc_lrmate200id_moveit_config /home/michalos/catkin_ws/src/fanuc_experimental/fanuc_lrmate200id_moveit_config
fanuc_lrmate200id_moveit_plugins /home/michalos/catkin_ws/src/fanuc_experimental/fanuc_lrmate200id_moveit_plugins
fanuc_lrmate200id_support /home/michalos/catkin_ws/src/fanuc_experimental/fanuc_lrmate200id_support
...


