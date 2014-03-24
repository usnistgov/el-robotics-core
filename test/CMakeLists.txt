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
message("In testMe directory")
project(testMe)

set(LIBRARY_OUTPUT_PATH ${IPMAS_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${IPMAS_DIR}/bin)

SET(testMe_SOURCES
    endEffect.cpp)

SET(testMe_LIBS sqlKit ipmasUtils pthread mysqlcppconn )

add_executable(testMe ${testMe_SOURCES})
link_directories(${LIBRARY_OUTPUT_PATH})

target_link_libraries(testMe ${testMe_LIBS})