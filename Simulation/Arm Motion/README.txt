This directory contains data from arm motion attempts that utilized the ROS
Fourte arm motion stack.Histogram.png and datafile1.dat contain random motion
attempts with the default settings on the arm wizzard.
Histogram2 and datafile2.dat contain data from the arm wizzard using the most complex solutions.
randCommand.txt is the canonical command file used to generate both datasets.
genPts.py is the python file that generated randCommand.txt

to recollect the data from the simulator, modifications to rosInf.cpp need to be made--uncomment the marked sections of code 
in navigationDoneCallback, and comment out the exit command.
The global position frame needs to be changed to /base_link instead of /odom (the call to nextGoal.setGlobalFrame() in addArmGoal) .
