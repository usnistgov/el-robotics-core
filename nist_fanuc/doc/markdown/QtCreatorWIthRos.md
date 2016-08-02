QT Creator and ROS
==================
QT is a cross-platform application framework that is widely used for developing application software that can be run on various software and hardware platforms, while still being a native application with the capabilities and speed thereof.
 
It was desired to use the Qt Creator IDE to edit and debug ROS packages. After a couple days of missteps the following worked for me. 
 
As a novice to Ubuntu and CMake, I suggest to first read this web site, which offers a good background tutorial, on Makfiles, make, cmake and catkin:
[http://jbohren.com/articles/gentle-catkin-intro/](http://jbohren.com/articles/gentle-catkin-intro/ "A Gentle Introduction to Catkin")
 
Installing QT Creator
--------------------
               sudo apt-get install qtcreator
This works. It is best to use from command line. Not sure if this loads the SDK and development libraries for QT. But first wanted to test Qt Creator.
 
Python catkin tools
------------------
One of the first of many insights to using Qt Creator with ROS was to use the Python based catkin tools instead of catkin_make.  This web site offers a thorough background on the Python catkin tools: [http://catkin-tools.readthedocs.org/en/latest/index.html](http://catkin-tools.readthedocs.org/en/latest/index.html "Catkin Command Line Tools").
 
Briefly, these steps were followed to get the python catkin tools to work:
 
1) Installed python catkin tools:
 
    sudo apt-get install python-catkin-tools
 
Note, if you have symbolic links you must manually cd to the actual directory, don't use any symlinks to get there:
 
    cd /usr/local/michalos
 
2) Reinitialize the catkin workspace with the new python catkin tools:
 
    catkin clean --all
    catkin init
    qtcreator
 
3) Open an individual  the new python catkin_tools, there is no longer a top level make file for the whole workspace. Instead, open each package as an individual project in QtCreator. The trick is to set the build folder to ws/build/your_package instead of ws/build as before.
 
QT Creator use with ROS
-----------------
From
`http://myzharbot.robot-home.it/blog/software/myzharbot-ros/qtcreator-ros`/
and
    `http://www.ciencia-explicada.com/2014/12/ros-how-to-develop-catkin-packages-from-an-ide.html`
 
In CMakeLists.txt add:
 
    set(ROS_BUILD_TYPE Debug)
    set(CMAKE_BUILD_TYPE Debug)
 
 
Invoke qtcreator from a terminal in which you have already setup the ROS environment (normally via .bashrc):
 
    qtcreator
 
Select the menu:
  `File -> "Open File or project…"`
then pick 
`~/catkin_ws/src/your package/CMakeLists.txt` and set the build dir to `~/catkin_ws/build/your package/` (where ~ stands for your home directory or in my case I used /usr/local/michalos and symbolic links to the actual src directories). Press Configure.
 
Select the tab `Projects -> Build Settings` and add these CMake arguments (I hard coded the directory paths):
 
    -DCMAKE_BUILD_TYPE=Debug \
               -DCMAKE_INSTALL_PREFIX=/usr/local/michalos/nistfanuc_ws/install \
               -DCATKIN_DEVEL_PREFIX=/usr/local/michalos/nistfanuc_ws/devel
   
 
This way it works for either all packages or an individual package.
 
Using Python catkin tools and debugging  ROS package in QT Creator
----------------------------------------------------------------
 
From `http://answers.ros.org/question/67244/qtcreator-with-catkin/` the answer can be summarized to:
 
1. compile the node/package that you want to compile in debug mode Either:
 
               a. add "`set(CMAKE_BUILD_TYPE Debug)`" to your CMakeLists.txt
 
               b. add `-DCMAKE_BUILD_TYPE=Debug` to the Build arguments
 
2. start your roscore and everything else as usual, except for the node you want to debug (in my case I started the rviz gui).
3. start qtcreator with "sudo" (remember to source correctly your catkin workspace)
4. in qtcreator start the debugging mode for the rosnode by going to "Debug"->"Start Debugging"->"Attach to unstarted Application...", look for your compiled node, it should be in: "`${CATKIN_WORKSPACE_FOLDER}"/devel/lib/package_name/node_name`" and click "Start Watching".
5. Debug:
               a) Either start in the debugger or
 
               b) start the node in a terminal either with rosrun or roslaunch
Note: you need to run qtcreator with "sudo", otherwise you get a "ptrace operation not allowed" problem. Note2: if you try to run qtcreator as a normal user afterwards, you will have problems accessing some of the Qt configuration files of your home folder, run these commands to get this back to normal:
 
    sudo chown -R ${USER}:${USER} .qt
    sudo chown -R ${USER}:${USER} .config/
 
Hey, there is another post in ROS Answers addressing how to debug a rosnode in Qtcreator: http://answers.ros.org/question/34966...
 
See ROS header files in Qt Project
---------------------------------------
ROS proposes the following code addition to CMakefile (see `http://wiki.ros.org/IDEs`)
 
               #Add all files in subdirectories of the project in
               # a dummy_target so qtcreator have access to all files
               FILE(GLOB children ${CMAKE_SOURCE_DIR}/*)
               FOREACH(child ${children})
                 IF(IS_DIRECTORY ${child})
                   file(GLOB_RECURSE dir_files "${child}/*")
                   LIST(APPEND extra_files ${dir_files})
                 ENDIF()
               ENDFOREACH()
               add_custom_target(dummy_${PROJECT_NAME} SOURCES ${extra_files})
 
 
Another solution (unused) is an answer
 
    http://answers.ros.org/question/56685/is-there-any-way-to-get-qt-creator-to-show-all-of-a-projects-subdirectories/
 
to the question "I've got many header files *.h and *.hxx which are included in several *.cpp files but do not show up in the project tree on qtcreator, is there any way of telling qtcreator that those files do belong to the project?"
 
The answer is do include header files in CMakeLists.txt similar to the following:
               set( MY_SRCS
               include/version.h
               include/idcache.h
               src/json.cpp
               include/json.h
               src/diskinfo.cpp
               include/diskinfo.h
               src/exif.cpp
               include/exif.h
               include/networkmanager.h
               include/networkmanager_p.h
               )
 
 
Catkin_make use with QT
----------------------
http://answers.ros.org/question/67244/qtcreator-with-catkin/
