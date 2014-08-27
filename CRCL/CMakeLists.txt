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

PROJECT(CRCL)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CRCL_DIR ${PROJECT_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(TinyXML REQUIRED)

add_subdirectory(schunk_powercube_driver)
include_directories(
  include
  # ${Boost_INCLUDE_DIRS}
  ../ulapi/src
  ../nist_core/include
  ../nist_kitting/include
  ./schunk_powercube_driver/schunk_libm5api/include
  )

## Declare a cpp library
add_library(nist_kitting
  ../nist_kitting/src/msg_types.cpp
#  src/kitting_utils.cpp
  ../ulapi/src/inifile.c
  ../ulapi/src/serial.c
  ../ulapi/src/ulapi_getopt.c
  ../ulapi/src/unix_rtapi.c
  ../ulapi/src/unix_ulapi.c
  src/timer.cc
  src/_timer.c
  )

## Declare a cpp executable
add_executable(kukaServer src/kukaServer.cpp src/kukaThread.cpp src/crclUtils.cpp src/trajectoryMaker.cpp src/kukaThreadArgs.cpp src/statusThread.cpp src/crclStatus.cpp)
add_executable(kukaRobot src/kukaRobot.cpp)
add_executable(crclClient src/crclClient.cpp src/statusThread.cpp src/crclStatus.cpp src/crclUtils.cpp)
## Specify libraries to link a library or executable target against
target_link_libraries(
  nist_kitting
  ${catkin_LIBRARIES}
  # ${Boost_LIBRARIES}
)
target_link_libraries(kukaServer nist_kitting pthread dl tinyxml m5api)
target_link_libraries(kukaRobot nist_kitting pthread dl tinyxml)
target_link_libraries(crclClient nist_kitting pthread dl tinyxml)
