cmake_minimum_required(VERSION 2.4.6)

project(canonicalController)

get_filename_component(IPMAS_DIRECTORY ${PROJECT_SOURCE_DIR} PATH)
message(${IPMAS_DIRECTORY})

#need to use a custom target since ROS is picky about cmake usage
add_custom_target(rosCanonicalController ALL
	COMMAND rosmake rosCanonicalController
	DEPENDS sqlKitTarget canonicalQueue
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/rosCanonicalController)

#add the sqlKit library to dependencies so it gets built if it hasn't already
#need to use a name other than "sqlKit" so that executables that link the library later in the tree don't get confused
add_custom_target(sqlKitTarget ALL
	COMMAND make
	WORKING_DIRECTORY ${IPMAS_DIRECTORY}/AutoGen)

add_subdirectory(canonicalQueue)
add_dependencies(canonicalQueue sqlKitTarget)
