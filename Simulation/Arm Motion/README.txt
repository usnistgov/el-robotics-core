This directory contains data from arm motion tests that utilized the ROS Fuerte arm motion stack.

-----------Tests-----------

test1: contains data and plots from an attempt to find the effectiveness of using repeated IK requests to improve IK success rates, and a comparison of success rates using different arm wizard settings.

test2: contains data and plots from a comparison of the success rates of two different IK solver plugins (the ROS default KDL plugin and openrave IKFast plugin). The test also compared different several different versions of the KR60 URDF within the KDL plugin.

test3: same as test2, but all collision models were removed from the URDF files and a new command generator was used to guarantee that all goals were within the arm's reach space.

The CRCL files used in each test are included in the test directories.


---------------Running Tests---------------

-Set the LOG_FAILURES flag in rosCanonicalController/include/rosInf.hh to 1
-If desired, adjust MAX_NAVIGATION_FAILURES (also defined in rosInf.hh). This will only have an effect if the KDL plugin is used
-Rebuild the rosCanonicalController
-Run ExampleMap.bat on windows, and launch the robot with desired IK solver configuration
-Then run:
$ ./genPts.py OR $ ./genSpacePts.py [to generate a new random command file]
$ rosrun rosCanonicalController rosCanonicalController randCommand.txt

data will be written to "datfile", in whichever directory the controller is run from.

------------Command File Generators---------------

genPts.py generates random goal points with random orientations in a 4.6x4.6x2.3 box, with the bottom center at the robot base_link. Commands are generated in ROS (+z up) coordinates.

genSpacePts.py uses the "compute" tool (built using ikfast solver source for KR60) to solve forward kinematics for random joint angles (joint limits are hard-coded into the script). It parses the output to produce the goal points, guaranteeing that each goal is in the arm's reach space.
Note that fk is computed with no tool attached to the arm, so this will work best if no gripper is attached during simulation.

Both scripts have the robot start position hard-coded in.

-------------URDF file variations-------------

"joint coordinates" or "old generator" refers to using transformed joint orientation frames in the URDF file so that the joint axis of rotation always points along +z.
"nojoint" or "new generator" means using the same orientation frame for every joint and changing the axis of rotation.
"box collisions" means using a 0.05x0.05 box, with a length 80% that of the actual arm link, as the collision model for the link.
"accurate collisions" or "real collisions" means using the collision models built in Blender from the arm visual models.
 "perp" or "hand-adjusted" means that the joint axes of rotation on the URDF model were adjusted to be perpendicular and axis-aligned. For instance, axes pointing along (0.002, -1.000, 0.000) were changed to (0.000, -1.000, 0.000).


The IKFast plugin uses the new generator and a hand-adjusted URDF, since it will NOT work otherwise. When collisions are enabled, it uses the more accurate collision models.
