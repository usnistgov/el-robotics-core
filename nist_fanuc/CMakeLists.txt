cmake_minimum_required(VERSION 2.8.3)
project(nist_fanuc)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  moveit_core
  roscpp
  cmake_modules
  descartes_core
  descartes_moveit
  descartes_trajectory
  descartes_planner
  trajectory_msgs
  sensor_msgs
    moveit_ros_planning_interface
    moveit_ros_move_group
    moveit_ros_planning
    moveit_ros_manipulation
)

find_package(Boost REQUIRED system thread chrono regex)
find_package(Eigen REQUIRED)

#The catkin_package function specifies which dependencies your package exports to its dependencies. In particular, #INCLUDE_DIRS specifies which directory in your package contains the header directory that should be on the include #path for any packages that compile against your package.

catkin_package(
  INCLUDE_DIRS
    include
    include/${PROJECT_NAME}/CrclXsd
  LIBRARIES
    
  CATKIN_DEPENDS
    roscpp
    moveit_core
    descartes_moveit
    descartes_core
    descartes_trajectory
    descartes_planner
    sensor_msgs
    moveit_ros_planning_interface
    moveit_ros_move_group
    moveit_ros_planning
    moveit_ros_manipulation
  DEPENDS
    Boost
    Eigen


#  CFG_EXTRAS
#    descartes_core-extras.cmake
)

###########
## Build ##
###########
# set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_CXX_FLAGS "-Wdeprecated-declarations ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-w ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-DDEBUG ${CMAKE_CXX_FLAGS}")

message("DEBUG variable catkin_INCLUDEDIR: ${catkin_INCLUDEDIR}")
message("DEBUG variable Eigen_INCLUDE_DIRS:  ${Eigen_INCLUDE_DIRS}")

include_directories(include
    ${catkin_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${Eigen_INCLUDE_DIRS}
    # include breakdown for this project
    include/${PROJECT_NAME}
    include/${PROJECT_NAME}/CrclXsd
    include/${PROJECT_NAME}/NIST

   ${descartes_moveit_INCLUDE_DIRS}
   ${descartes_trajectory_INCLUDE_DIRS}
   ${descartes_planner_INCLUDE_DIRS}
   ${descartes_core_INCLUDE_DIRS}
   /usr/include/eigen3
)
# Codesynthesis include
# FMP
include_directories(
  /usr/include/xsd/cxx/xml
  /usr/local/include/xsd/cxx/xml
  )
# Apache xercesc include
include_directories(/usr/include/xercesc)



add_executable(nist_fanuc 

src/CRCL/CRCLCommandInstance.cxx
src/CRCL/CRCLCommands.cxx 
src/CRCL/CRCLProgramInstance.cxx
src/CRCL/CRCLStatus.cxx
src/CRCL/DataPrimitives.cxx
src/AsioCrclServer.cpp
src/crcl.cpp
src/CrclInterface.cpp
src/Controller.cpp
src/RCS.cpp
src/RCSInterpreter.cpp
src/urdf_parse_model.cpp
src/Globals.cpp
src/Kinematics.cpp
src/Trajectory.cpp
src/MotionControl.cpp
src/nist_fanuc.cpp
src/Communication.cpp
src/Setup.cpp
src/moveit.cpp
src/trajectoryMaker.cpp
src/Conversions.cpp
src/RvizMarker.cpp
)

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



link_directories(/usr/lib/x86_64-linux-gnu/)

target_link_libraries(nist_fanuc 
libtinyxml.a  
libxerces-c.a  
${catkin_LIBRARIES}
${Boost_LIBRARIES}
)

catkin_add_gtest(crclmathunittest test/crclmathtest.cpp)

#############
## Install ##
#############
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


install(
    DIRECTORY include/${PROJECT_NAME}/
    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
