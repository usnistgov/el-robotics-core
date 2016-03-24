Netbeans IDE use with ROS
=========================

This page describes some insights/tips into using Netbeans with ROS and catkin_make.

Using Netbeans IDE to Debug ROS executable
-----------------------------
After Compiling Fanuc Demo with Debug Information,
Use netbeans to create binary C++ project and read binary file to debug
(for example found at */home/michalos/catkin_ws/devel/lib/nist_fanuc/nist_fanuc*)


Running Netbeans without Environment setup properly
======================================================
Unfortunately, you need to source ~/catkin_ws/devel/setup.bash to set up Unix shell enironment
variables properly. Since it was not obvious how to run a bash shell before debugging the executable, 
it was decided a different approach must be used. (running a bash script with gdb was attempted). 
Instead environment variables were hard coded into the nist_fanuc program, with the use of the posix 
function "setenv" to set the environment variables (not perfect, but close enough between addition of new 
ROS packages).  

To make it work, I did

    > env | grep indigo
  
to find all the related ROS environment variables. 
From http://answers.ros.org/question/123581/rosrun-cannot-find-my-executable/ found:

    catkin_find uses the environment variable CMAKE_PREFIX_PATH to find catkin workspaces.
 
These workspaces in turn are used in rosrun. ROS_PACKAGE_PATH is no longer enough.

This works, no claims of robustness.  The following code
was placed at the beginning of the nist_fanuc.cpp to set up the environment variables before 
connecting to the roscore (master). (This assumes that all the basic rviz, robot model, etc. has been
launched.)  In the code:

    static void SetupRos(std::string  envname, std::string envval, int overwrite=1)
    {
            setenv( envname.c_str(),envval.c_str(),1 );
    }

           // Setup up environment for netbeans that allows ros utilities to work...
            SetupRos("ROS_MASTER_URI", "http://localhost:11311");
            SetupRos("ROS_DISTRO", "indigo");
            SetupRos("ROS_ROOT", "/opt/ros/indigo/share/ros");
            SetupRos("ROS_ETC_DIR", "/opt/ros/indigo/etc/ros");
            SetupRos("ROS_PACKAGE_PATH", "/home/michalos/catkin_ws/src:/opt/ros/indigo/share:/opt/ros/indigo/stacks");
            SetupRos("ROS_TEST_RESULTS_DIR", "/home/michalos/catkin_ws/build/test_results");
            SetupRos("ROS_ETC_DIR", "/opt/ros/indigo/etc/ros");
            SetupRos("OSLISP_PACKAGE_DIRECTORIES", "/home/michalos/catkin_ws/devel/share/common-lisp");
            SetupRos("PYTHONPATH", "/home/michalos/catkin_ws/devel/lib/python2.7/dist-packages:/opt/ros/indigo/lib/python2.7/dist-packages");
            SetupRos("CMAKE_PREFIX_PATH", "/home/michalos/catkin_ws/devel:/opt/ros/indigo");
            SetupRos("PATH", "/home/michalos/catkin_ws/devel/bin:/opt/ros/indigo/bin:/home/michalos/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
            SetupRos("PKG_CONFIG_PATH", "/home/michalos/catkin_ws/devel/lib/x86_64-linux-gnu/pkgconfig:/opt/ros/indigo/lib/x86_64-linux-gnu/pkgconfig:/home/michalos/catkin_ws/devel/lib/pkgconfig:/opt/ros/indigo/lib/pkgconfig");

This does not improve the performance of Netbeans.(Often hogging up to 1G! per executable.) 

I could rant/rave about Java, but won't. Better than nothing - must be patient as often it takes time to reload the executable.

Turn off auto paren completion in Netbeans - really annoying
---------------------------------------

    Tools->Options
    Editor->Code Completion


tf include location
--------------------
    /opt/ros/indigo/include/tf/LinearMath
    
Netbeans Turn on/off Exception Breakpoints 
-----------------------------------------
###To turn on breakpoint:  ###
It's often useful to stop execution of an application when an exception occurs, and inspect the state of the app in debugger. It is very simple to do: setup an exception breakpoint and just run the application via debugger (or attach to an running application).

To setup an exception breakpoint:

    Go to menu Debug | New Breakpoint (Ctrl+Shift+F8).

In the New Breakpoint dialog select the Exception breakpoint type from the combobox.

Enter the exception to track (fully qualified class name).
You can modify the other properties too.

Typically you want to watch for some general exception superclass, e.g. java.lang.Exception, or exceptions that do not have to be handled, e.g. java.lang.AssertionError, or java.lang.RuntimeException.

In a bigger application you may want to narrow the scope of classes to watch for exceptions only from your classes, not to stop on exceptions from JDK internals or other code. You can set a match or exclude class filter in the Filter on Classes Throwing the Exception option of the breakpoint dialog.

###To turn off breakpoint:  ###


Select menu Window / Debugging / Breakpoints (or press Alt + Shift + 5), then right-click in the Breakpoints window and select Delete All.