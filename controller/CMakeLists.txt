cmake_minimum_required(VERSION 2.4.6)

project(canonicalController)

get_filename_component(IPMAS_DIRECTORY ${PROJECT_SOURCE_DIR} PATH)
message(${IPMAS_DIRECTORY})

#need to use a custom target since ROS is picky about cmake usage
add_custom_target(rosCanonicalController ALL
	COMMAND rosmake rosCanonicalController
	DEPENDS ${PROJECT_SOURCE_DIR}/canonicalQueue/lib/libcanonicalQueue.a
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/rosCanonicalController)

add_subdirectory(canonicalQueue)
#need to use add_custom_target because ROS is picky about cmake usage

