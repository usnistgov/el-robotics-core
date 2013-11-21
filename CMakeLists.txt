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

project(ipmas)
set(IPMAS_DIR ${PROJECT_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(AutoGen)
add_subdirectory(controller)
