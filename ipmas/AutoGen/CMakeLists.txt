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
message("In AutoGen directory")

project(AutoGen)
set(OWL_FILE ${IPMAS_DIR}/Ontology/Kitting/kittingWorkstationClasses.owl)
set(AutoGen_DIR ${IPMAS_DIR}/AutoGen/src)
file(GLOB libsqlKit_SOURCES "./src/*.cpp")
#file(GLOB libsqlKit_INCLUDES "./database/*.hh")
include_directories(${IPMAS_DIR}/AutoGen)

set (addfiles ${libsqlKit_SOURCES})
#set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${addfiles})

add_custom_command(OUTPUT ${AutoGen_DIR}/genSrc.cpp
                 COMMAND java -jar ${IPMAS_DIR}/Generator/generator_no_gui.jar -owl ${OWL_FILE} -cpp ${AutoGen_DIR}
                 COMMAND mv ${AutoGen_DIR}/*.h database
                 COMMAND touch ${AutoGen_DIR}/genSrc.cpp
		 COMMAND echo //////////////////////////////////////////////////////
		 COMMAND echo "NEW FILES ADDED IN AUTOGEN DIRECTORY. RERUN CMAKE!!!"
		 COMMAND echo //////////////////////////////////////////////////////
                 MAIN_DEPENDENCY ${OWL_FILE}
		 COMMENT "Generate .cpp and .hh files from ontoloyg"
#		 message( FATAL_ERROR "CMake will now exit." )
		 )
add_library(sqlKit STATIC ${libsqlKit_SOURCES} ${AutoGen_DIR}/genSrc.cpp)
