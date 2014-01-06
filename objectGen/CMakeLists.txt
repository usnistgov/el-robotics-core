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
message("In objectGen directory")
project(objectGen)
#include_directories(${IPMAS_DIR}/AutoGen ${IPMAS_DIR}/utils/include ${IPMAS_DIR}/objectGen/include)

set(LIBRARY_OUTPUT_PATH ${IPMAS_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${IPMAS_DIR}/bin)

SET(objectGen_SOURCES
    src/objectGen.cpp 
    src/usarSimInf.cpp 
    src/genericModel.cpp)

SET(objectGen_LIBS sqlKit ipmasUtils pthread mysqlcppconn )

add_executable(objectGen ${objectGen_SOURCES})
link_directories(${LIBRARY_OUTPUT_PATH})

target_link_libraries(objectGen ${objectGen_LIBS})