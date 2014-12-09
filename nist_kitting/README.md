# NIST Kitting

Application code for a robotic kitting demonstration, using the Core Robot Command Language (CRCL) XML messaging schemas, and the Planning Domain Description Language (PDDL) ontology.

## Running the Demo

Determine the absolute path to the .ini file you are using. Call this "inifile_name".

Determine the absolute path to the program/script you use for the planning application, e.g., /home/you/demo/kitting_demo.sh. We'll refer to this as "planning_app" below.

Determine the absolute path to the program/script you use to execute the plan. This is "<path/to/github>/el-robotics-core/nist_kitting/src/plan_exec_app" for now.

In one terminal, run (all on one line):

> roslaunch nist_kitting kitting_pl_hi.launch inifile_name:=<inifile_name> planning_app:=<planning_app> plan_exec_app:=<path/to/github>/el-robotics-core/nist_kitting/src/plan_exec_app

This would look something like this (all on one line):

> roslaunch nist_kitting kitting_pl_hi.launch inifile_name:=/home/proctor/github/el-robotics-core/nist_kitting/src/ini.ini planning_app:=/home/proctor/github/el-robotics-core/nist_kitting/src/planning_app plan_exec_app:=/home/proctor/github/el-robotics-core/nist_kitting/src/plan_exec_app 

In another terminal, run the HMI stand-in for the iPad app, and provide the TCP port to connect to:

> rosrun nist_kitting kitting_hmi.py -p 6066

Fill in the host and port, e.g., localhost and 6066, "Connect", fill in the kit name, and "Make" it. You should see the status information in the right side of the HMI changing as the planning and execution progress.

