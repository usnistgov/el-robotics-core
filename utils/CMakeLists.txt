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
message("In utils directory")

set(libipmasUtils_SOURCES src/ulapi.cpp
                          src/recurseLocation.cpp)

#link_directories(${LIBRARY_OUTPUT_PATH})

add_library(ipmasUtils STATIC ${libipmasUtils_SOURCES})

