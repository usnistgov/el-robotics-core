This directory contains data from arm motion tests that utilized the ROS Fuerte arm motion stack.

The test1 directory contains data and plots from an attempt to find the effectiveness of using repeated IK requests to improve IK success rates, and a comparison of success rates using different arm wizard settings.
The test2 directory contains data and plots from a comparison of the success rates of two different IK solver plugins (the ROS default KDL plugin and openrave IKFast plugin). The test also compared different several different versions of the KR60 URDF within the KDL plugin.
The CRCL files used in each test are included in the test directories.

To run these tests:

-Set the LOG_FAILURES flag in rosCanonicalController/include/rosInf.hh to 1
-If desired, adjust MAX_NAVIGATION_FAILURES (also defined in rosInf.hh). This will only have an effect if the KDL plugin is used
-Rebuild the rosCanonicalController
-Run ExampleMap.bat on windows, and launch the robot with desired IK solver configuration
-Then run:
$ ./genPts.py [to generate a new random command file]
$ rosrun rosCanonicalController rosCanonicalController randCommand.txt

data will be written to "datfile", in whichever directory the controller is run from.
