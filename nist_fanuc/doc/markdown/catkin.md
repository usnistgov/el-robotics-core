Catkin command line tools
========================

For a good background read the doc at htt: `http://catkin-tools.readthedocs.org/en/latest/`

Quick overview of useful catkin commands:

	catkin clean --build --devel

just clean a single package:

        catkin clean PKGNAME

Building ros packages

	catkin build   

Setting and unsetting CMake options:

        catkin config --cmake-args -DENABLE_CORBA=ON -DCORBA_IMPLEMENTATION=OMNIORB
        catkin config --no-cmake-args

Create “Debug” and “Release” profiles and then build them in independent build and devel spaces:

    catkin config --profile debug -x _debug --cmake-args -DCMAKE_BUILD_TYPE=Debug
    catkin config --profile release -x _release --cmake-args -DCMAKE_BUILD_TYPE=Release
    catkin build --profile debug
    catkin build --profile release

build specific packages (however this will build dependency packages)

	build PKG [PKG ...]






Initialize catkin workspace
--------------------------------

	source /opt/ros/indigo/setup.bash          # Source ROS indigo to use Catkin
	mkdir -p /tmp/quickstart_ws/src            # Make a new workspace and source space
	cd /tmp/quickstart_ws                      # Navigate to the workspace root
	catkin init     

Build one catkin project
-------------------------
If you’re only interested in building a single package in a workspace, you can also use the --no-deps option along with a package name. This will skip all of the package’s dependencies, build the given package, and then exit.

	catkin build PKG --no-deps # Build PKG only
	
Use some but not all of the processor cores
-------------------------------------------
You can control the number of build jobs. Typically a job controller is used and all the cores are assigned make files, which halts GUI interaction.

You can control the maximum number of packages allowed to build in parallel by using the -p or --parallel-packages option and you can change the number of make jobs available with the -j or --jobs option.

To disable the job server, you can use the --no-jobserver option.

	catkin build PKG --no-deps -p 7 # Build PKG only, and use only 7 or 8 cores


Building With Warnings
-------------------------
It can sometimes be useful to compile with additional warnings enabled across your whole catkin workspace. To achieve this, use a command similar to this:

	$ catkin build -v --cmake-args -DCMAKE_C_FLAGS="-Wall -W -Wno-unused-parameter"

This command passes the `-DCMAKE_C_FLAGS=`... argument to all invocations of cmake.



