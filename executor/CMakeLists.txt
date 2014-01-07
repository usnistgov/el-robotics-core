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
message("In executor directory")
project(executor)
#include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

#SET(ROSBUILD_DONT_REDEFINE_PROJECT TRUE)
#rosbuild_init()

set(LIBRARY_OUTPUT_PATH ${IPMAS_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${IPMAS_DIR}/bin)

#to get ROS to understand that it's not in the root cmake directory
#get_filename_component(CONTROLLER_DIRECTORY ${PROJECT_SOURCE_DIR} PATH)
#get_filename_component(IPMAS_DIRECTORY ${CONTROLLER_DIRECTORY} PATH)

SET(libExecutor_SOURCES src/CanonicalRobotCommand.cpp
                        src/Operator.cpp
			src/KittingPlan.cpp
			src/KittingPDDLProblem.cpp
			src/IniFile.cpp
			src/DatabaseUpdate.cpp)

SET(executor_LIBS Executor ipmasUtils sqlKit pthread mysqlcppconn)

link_directories(${LIBRARY_OUTPUT_PATH})
include_directories(${IPMAS_DIR}/executor/include)

add_library(Executor STATIC ${libExecutor_SOURCES})

add_executable(executor src/executor.cpp)

target_link_libraries(executor ${executor_LIBS})
