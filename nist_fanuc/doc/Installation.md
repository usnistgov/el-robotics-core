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

    link_directories(/usr/lib/x86_64-linux-gnu/)
 
 
 
3) Installing CodeSynthesis XSD
---------------------------------------
http://www.codesynthesis.com/products/xsd/download.xhtml
1. Chose the linux deb install file that matches your computer (below 64 bit amd).
2. Download xsd_4.0.0-1_amd64.deb and it will say open with Ubuntu Software Center
3. Click to install, authenticate and add /usr/include/xsd/cxx/xml as include path.
 
Need include file path in CMakeLists.txt:
    include_directories(/usr/include/xsd/cxx/xml)
