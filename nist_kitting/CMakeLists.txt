##
##----------------------------------------------------------------------------
##--  Copyright 2012-2013
##--  Georgia Tech Research Institute
##--  505 10th Street
##--  Atlanta, Georgia 30332
##--
##--  This material may be reproduced by or for the U.S. Government
##--  pursuant to the copyright license under the clause at DFARS
##--  252.227-7013 (October 1988).
##----------------------------------------------------------------------------
##
## DISCLAIMER:
## This software was originally produced by the National Institute of Standards
## and Technology (NIST), an agency of the U.S. government, and by statute is
## not subject to copyright in the United States.  
##
## Modifications to the code have been made by Georgia Tech Research Institute
## and these modifications are subject to the copyright shown above
##****************************************************************************/

cmake_minimum_required(VERSION 2.8.3)

project(nist_kitting)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  ulapi
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system filesystem date_time thread)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  # ${Boost_INCLUDE_DIRS}
  ../ulapi/src
  ../nist_core/include
  )

## Declare a cpp library
add_library(nist_kitting
  src/msg_types.cpp
  src/kitting_utils.cpp
  ../ulapi/src/inifile.c
  ../ulapi/src/serial.c
  ../ulapi/src/ulapi_getopt.c
  ../ulapi/src/unix_rtapi.c
  ../ulapi/src/unix_ulapi.c
  )

## Declare a cpp executable

#add_executable(kitting_ws_node src/kitting_ws.cpp)
#add_executable(kitting_task_node src/kitting_task.cpp)
#add_executable(kitting_emove_node src/kitting_emove.cpp)
#add_executable(kitting_prim_robot_node src/kitting_prim_robot.cpp)
#add_executable(kitting_sh src/kitting_sh.cpp)
add_executable(crcl_server src/crcl_server.cpp   
  ../nist_core/src/crcl_sim_robot.cpp
)
#add_executable(simple_robot src/simple_robot.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
#add_dependencies(kitting_ws_node nist_kitting_generate_messages_cpp)
#add_dependencies(kitting_task_node nist_kitting_generate_messages_cpp)
#add_dependencies(kitting_emove_node nist_kitting_generate_messages_cpp)
#add_dependencies(kitting_prim_robot_node nist_kitting_generate_messages_cpp)
#add_dependencies(kitting_sh nist_kitting_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(
  nist_kitting
  ${catkin_LIBRARIES}
  # ${Boost_LIBRARIES}
)

#target_link_libraries(kitting_ws_node nist_kitting ${catkin_LIBRARIES})
#target_link_libraries(kitting_task_node nist_kitting ${catkin_LIBRARIES})
#target_link_libraries(kitting_emove_node nist_kitting ${catkin_LIBRARIES})
#target_link_libraries(kitting_prim_robot_node nist_kitting ${catkin_LIBRARIES})
#target_link_libraries(kitting_sh nist_kitting ${catkin_LIBRARIES} readline)
target_link_libraries(crcl_server nist_kitting pthread dl)
#target_link_libraries(simple_robot nist_kitting ${catkin_LIBRARIES})
