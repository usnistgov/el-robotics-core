Installation Readme
======================
 
1) Set up ROS with Descartes and ROS Industrial
-----------------------------
Copy repositories from https://github.com/ros-industrial:

    fanuc
    fanuc experimental
    motoman
    ros industrial core
 
Repositories from ROS-I Consortium https://github.com/ros-industrial-consortium github site:

    descartes
    descartes_tutorials
 
 
2) Installing Xerces c with Ubuntu
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

    target_link_libraries(nist_fanuc 
    libxerces-c.a  
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
    )
 
 
 
3) Installing CodeSynthesis XSD
---------------------------------------
http://www.codesynthesis.com/products/xsd/download.xhtml
1. Chose the linux deb install file that matches your computer (below 64 bit amd).
2. Download xsd_4.0.0-1_amd64.deb and it will say open with Ubuntu Software Center
3. Click to install, authenticate and add /usr/include/xsd/cxx/xml as include path.
 
Need include file path in CMakeLists.txt:

    include_directories(/usr/include/xsd/cxx/xml)

If you  cannot run Ubuntu software centerto install CodeSynthesis, you can download the source and install it.
You need to go to the web page: http://www.codesynthesis.com/products/xsd/download.xhtml and select:

    xsd-4.0.0-x86_64-linux-gnu.tar.bz2
 
It  will be saved into /usr/local/downloads, but you can save it anywhere. Then cd to where you saved it, and do this:
 
    tar --bzip2 -xvf xsd-4.0.0-x86_64-linux-gnu.tar.bz2 (dash-dash bzip2, dash-xvf)
 
It will create a directory xsd-4.0.0-x86_64-linux-gnu.
 
Make a symbolic link:
 
    ln -s <path/to/xsd-4.0.0-x86_64-linux-gnu/libxsd/xsd /usr/local/include/xsd

e.g., 
	ln -s /usr/local/xsd-4.0.0-x86_64-linux-gnu/libxsd/xsd /usr/local/include/xsd

4) Optionally - download netbeans
--------------------------------
https://netbeans.org/downloads/

cd to the directory where you downloaded netbeans:

	./netbeans-8.1-cpp-linux-x64.sh


5) Setup ROS workspace
-------------------

	$ source /opt/ros/indigo/setup.bash

Let's create a catkin workspace:

	$ mkdir -p /home/local/michalos/catkin_ws/src
	$ cd /home/local/michalos/catkin_ws/src
	$ catkin_init_workspace

Now you can add your packages to the ROS catkin workspace. For those
packages you cloned from GITHUB, you will need to symbolically link the package directory to the github local directory)) 

	$ mkdir -p /usr/local/github/ros-industrial
	$ cd /usr/local/github/ros-industrial
	$ git clone https://github.com/ros-industrial/fanuc_experimental.git
	$ cd /home/local/michalos/catkin_ws/src
	$ ln -s  /usr/local/github/ros-industrial/fanuc_experimental fanuc_experimental

And do for descartes, nist_fanuc, etc. 


6) Compile ROS packages
------------------------

	$ cd /home/local/michalos/catkin_ws
	$ catkin_make -DCMAKE_BUILD_TYPE=Debug

7) Run ROS Simulator
---------------------

	$ cd /usr/local/michalos/
	$ cd nistfanuc_ws/
	$ source devel/setup.bash
	$roslaunch fanuc_lrmate200id_moveit_config moveit_planning_execution.launch sim:=true 

8) Install Java 1.08 from Oracle for Java CRCL Tool
---------------------------------------------------
To build java crcl tool one needs:

    JDK 1.8+ (http://www.oracle.com/technetwork/java/javase/downloads/index.html) and
    maven 3.0.5+ (https://maven.apache.org/download.cgi)

Install maven:
	$ sudo apt-get install maven


Use the command:

	mvn package

If you see this message at the beginning, bummer:

	Warning: JAVA_HOME environment variable is not set. 

You can check /usr/lib/jvm to see if a 1.8 Java Virtual Machine has been installed. If so, skip the installation step.

So you do not have Java installed. These are instructions for the less than sudo installers. Note, you need the Oracle Java JDK 1.8 version, not the 1.7 version of Ubuntu!!!

Download, unzip and copy to /usr/local/jdk1.8.0_77
or whatever is the latest 1.8 version. 

Change  you will need to change .bashrc to set the PATH to know where the jdk is installed:

	for dir in /usr/local/jdk1.8.0_77/bin /usr/lib/jvm/java-[6,7,8]-*/bin /usr/local/jdk*/bin /usr/local/jdk*/bin ; do
	  if [ -x $dir/java ] ; then
	    javadir=$dir
	  fi
	done
	if [ x"$javadir" = x ] ; then javadir=/usr/bin ; fi

	# platform-specific environment vars

	THISPLAT=`uname -s` ; export THISPLAT

	case $THISPLAT in
	    Linux)
	    PATH=$javadir:

And make sure you source the .bashrc before you attempt run.sh in java crcl. The voodoo worked for me.



9) Install doxygen for documentation generation
--------------------------------------------------

	$ sudo apt-get install doxygen


