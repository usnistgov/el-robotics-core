# NIST Kitting

Application code for a robotic kitting demonstration, using the Core Robot Command Language (CRCL) XML messaging schemas, and the Planning Domain Description Language (PDDL) ontology.

## Setting up ROS 

Create a catkin workspace:
> mkdir -p ~/catkin_ws/src

> cd ~/catkin_ws/src

> catkin_init_workspace

Create symbolic links to the nist\_core, nist\_kitting, and ulapi directories in the ~/catkin_ws/src directory:
> cd ~/catkin_ws/src

> ln -s "\<path/to/github\>/el-robotics-core/nist_core"

> ln -s "\<path/to/github\>/el-robotics-core/nist_kitting"

> ln -s "\<path/to/github\>/el-robotics-core/ulapi"

Build the workspace:

> cd ~/catkin_ws/
> catkin_make

The catkin_make command is a convenience tool for working with catkin workspaces. If you look in your current directory you should now have a 'build' and 'devel' folder. Inside the 'devel' folder you can see that there are now several setup.\*sh files. Sourcing any of these files will overlay this workspace on top of your environment. To understand more about this see the general catkin documentation: catkin. Before continuing source your new setup.\*sh file:

> source devel/setup.bash

## Running the January 2015 Demo

In one termina, run the Cognex simulator:
```
rosrun nist_kitting cognex_sim -f $HOME/github/el-robotics-core/nist_kitting/src/cognex_sim.txt
```
In another terminal, run the MySQL pose updater:
```
cd $HOME/github/el-robotics-core/CognexToMysql/src
java -cp .:../3rdPartyLibs/mysql-connector-java-5.1.28.jar  cognex_to_mysql.Main
```
A GUI will come up. "Connect to Cognex" on port 1456. You should see the pane of Cognex object coordinates become populated at the right. 

In another terminal, run the controller:
```
roslaunch nist_kitting kitting_pl_hi.launch inifile_name:=$HOME/github/el-robotics-core/nist_kitting/src/ini.ini
```
The GUI will come up. "Connect" to the host, e.g., localhost on port 6066. You should see the status information being updated at the right. 

"Browse" to a kit file, then "Make" the kit. You should see the status information change to "Exec", and see lots of debugging information being printed in the controller terminal.

## Running the Demo

Determine the absolute path to the .ini file you are using. Call this "inifile_name".

Determine the absolute path to the program/script you use for the planning application, e.g., /home/you/demo/kitting_demo.sh. We'll refer to this as "planning_app" below.

Determine the absolute path to the program/script you use to execute the plan. This is "\<path/to/github\>/el-robotics-core/nist_kitting/src/plan_exec_app" for now.

In one terminal, run (all on one line, no spaces around the ":=" assignments):

> roslaunch nist_kitting kitting_pl_hi.launch inifile_name:=\<inifile_name\> planning_app:=\<planning_app\> plan_exec_app:=\<path/to/github\>/el-robotics-core/nist_kitting/src/plan_exec_app

This would look something like this (all on one line):

> roslaunch nist_kitting kitting_pl_hi.launch inifile_name:=/home/isd/proctor/github/el-robotics-core/nist_kitting/src/ini.ini planning_app:=/home/isd/proctor/github/el-robotics-core/nist_kitting/src/planning_app plan_exec_app:=/home/isd/proctor/github/el-robotics-core/nist_kitting/src/plan_exec_app 

In another terminal, run the HMI stand-in for the iPad app, and provide the TCP port to connect to:

> rosrun nist_kitting kitting_hmi.py -p 6066

Fill in the host and port, e.g., localhost and 6066, "Connect", fill in the kit name, and "Make" it. You should see the status information in the right side of the HMI changing as the planning and execution progress.

