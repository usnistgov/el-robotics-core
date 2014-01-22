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
message("In canonicalQueue directory")

include_directories(./include)
set(libcanonicalQueue_SOURCES ./src/commandParser.cpp ./src/controller.cpp ./src/canonicalMsg.cpp)
set(commandParserTest_SOURCES ./src/commandParserMain.cpp ./src/myController.cpp)
set(canonicalController_LIBS sqlKit pthread mysqlcppconn)

add_library(canonicalQueue STATIC ${libcanonicalQueue_SOURCES})
add_executable(commandParserTest ${commandParserTest_SOURCES})
link_directories(${LIBRARY_OUTPUT_PATH})

target_link_libraries(commandParserTest ipmasUtils canonicalQueue ${canonicalController_LIBS})
