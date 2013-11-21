#------------------------------------------------------------------------------
#--  Copyright 2012-2013
#--  Georgia Tech Research Institute
#--  505 10th Street
#--  Atlanta, Georgia 30332
#--
#--  This material may be reproduced by or for the U.S. Government
#--  pursuant to the copyright license under the clause at DFARS
#--  252.227-7013 (October 1988).
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.6)
cmake_policy(VERSION 2.6)
message("In rosCanonicalController directory")
project(rosCanonicalController)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

SET(ROSBUILD_DONT_REDEFINE_PROJECT TRUE)
rosbuild_init()
#set(LIBRARY_OUTPUT_PATH ../../../lib)
set(LIBRARY_OUTPUT_PATH ${IPMAS_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${IPMAS_DIR}/bin)

#to get ROS to understand that it's not in the root cmake directory
get_filename_component(CONTROLLER_DIRECTORY ${PROJECT_SOURCE_DIR} PATH)
get_filename_component(IPMAS_DIRECTORY ${CONTROLLER_DIRECTORY} PATH)

SET(librosControl_SOURCES src/rosControl/rosInf.cpp
                       src/rosControl/navigationGoal.cpp
                       src/rosControl/rosController.cpp
                       src/rosControl/robotDescription.cpp)

#SET(binPickup_SOURCES src/binPickup/scanPattern.cpp src/binPickup/scanPickup.cpp)

SET(roscontroller_LIBS canonicalQueue rosControl pthread sqlKit mysqlcppconn)

link_directories(${LIBRARY_OUTPUT_PATH})
#link_directories(../../../lib)
#include_directories(${CONTROLLER_DIRECTORY}/canonicalQueue ${CMAKE_CURRENT_BINARY_DIR} ${IPMAS_DIRECTORY}/AutoGen)
include_directories(${CONTROLLER_DIRECTORY}/canonicalQueue ${IPMAS_DIRECTORY}/AutoGen)

rosbuild_add_library(rosControl STATIC ${librosControl_SOURCES})

rosbuild_add_executable(rosCanonicalController src/canonicalController.cpp)

#target_link_libraries(rosControl pthread sqlKit mysqlcppconn)
target_link_libraries(rosCanonicalController ${roscontroller_LIBS})
