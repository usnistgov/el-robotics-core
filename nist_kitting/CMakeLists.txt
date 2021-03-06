cmake_minimum_required(VERSION 2.8.3)

project(nist_kitting)

set(ROS_BUILD_TYPE Debug)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  genmsg
  moveit_ros_planning_interface
  nist_core
  ulapi
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system filesystem date_time thread)

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(DIRECTORY msg
  FILES 
  ws_cmd.msg
  ws_stat.msg
  ws_assemble_kit.msg
  task_cmd.msg
  task_move_object.msg
  task_stat.msg
  emove_cmd.msg
  emove_move.msg
  emove_run.msg
  emove_stat.msg
  prim_robot_cmd.msg
  prim_robot_moveto.msg
  prim_robot_stop.msg
  prim_robot_set_abs_speed.msg
  prim_robot_close_gripper.msg
  prim_robot_open_gripper.msg
  prim_robot_stat.msg
  gripper_stat.msg
)

## Generate services in the 'srv' folder
# add_service_files(DIRECTORY srv FILES Srv.srv)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES std_msgs geometry_msgs nist_core nist_kitting)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES nist_kitting ulapi
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
  # DEPENDS boost
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  # ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  )

## Declare a cpp library
add_library(nist_kitting
  src/msg_types.cpp
  src/kitting_utils.cpp
  )

## Declare a cpp executable
add_executable(kitting_pl_hi_node src/kitting_pl_hi.cpp)
add_executable(kitting_ws_node src/kitting_ws.cpp)
add_executable(kitting_task_node src/kitting_task.cpp)
add_executable(kitting_emove_node src/kitting_emove.cpp)
add_executable(kitting_sh src/kitting_sh.cpp)
add_executable(irclient_sh src/irclient_sh.cpp)
add_executable(kitting_run src/kitting_run.cpp)
add_executable(kitting_hmi_proxy src/kitting_hmi_proxy.cpp)

add_executable(simple_message_sim src/simple_message_sim.cpp)
add_executable(simple_message_sh src/simple_message_sh.cpp)
add_executable(cognex_sim src/cognex_db.cpp src/cognex_sim.cpp)
add_executable(simple_message_to_cognex src/cognex_db.cpp src/simple_message_to_cognex.cpp)

add_executable(move_group src/move_group.cpp)
add_executable(planner src/planner.cpp)
add_executable(mover src/mover.cpp)

# add_executable(kitting_prim_robot_node src/kitting_prim_robot.cpp)
# add_dependencies(kitting_prim_robot_node nist_kitting_generate_messages_cpp)
# target_link_libraries(kitting_prim_robot_node nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})

# add_executable(crcl_server src/crcl_server.cpp)
# target_link_libraries(crcl_server nist_kitting ${catkin_LIBRARIES})

# add_executable(crobot src/crobot.cpp)
# target_link_libraries(crobot nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(kitting_pl_hi_node nist_kitting_generate_messages_cpp)
add_dependencies(kitting_ws_node nist_kitting_generate_messages_cpp)
add_dependencies(kitting_task_node nist_kitting_generate_messages_cpp)
add_dependencies(kitting_emove_node nist_kitting_generate_messages_cpp)
add_dependencies(kitting_sh nist_kitting_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(
  nist_kitting
  ${ulapi_LIBRARIES}
  ${catkin_LIBRARIES}
  # ${Boost_LIBRARIES}
)

target_link_libraries(kitting_pl_hi_node nist_kitting ${catkin_LIBRARIES})
target_link_libraries(kitting_ws_node nist_kitting ${catkin_LIBRARIES})
target_link_libraries(kitting_task_node nist_kitting ${catkin_LIBRARIES})
target_link_libraries(kitting_emove_node nist_kitting ${catkin_LIBRARIES})
target_link_libraries(kitting_sh nist_kitting ${catkin_LIBRARIES} readline)
target_link_libraries(irclient_sh nist_kitting ${catkin_LIBRARIES} readline)
target_link_libraries(kitting_run nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})
target_link_libraries(kitting_hmi_proxy nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})

target_link_libraries(simple_message_sim nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})
target_link_libraries(simple_message_sh nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})
target_link_libraries(cognex_sim nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})
target_link_libraries(simple_message_to_cognex nist_kitting ${ulapi_LIBRARIES} ${catkin_LIBRARIES})

target_link_libraries(move_group nist_kitting ${catkin_LIBRARIES} readline)
target_link_libraries(planner nist_kitting ${catkin_LIBRARIES} readline)
target_link_libraries(mover nist_kitting ${catkin_LIBRARIES} readline)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS nist_kitting nist_kitting_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.sg. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_nist_kitting.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
