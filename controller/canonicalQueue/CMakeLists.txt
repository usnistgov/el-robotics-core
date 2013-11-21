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

set(libcanonicalQueue_SOURCES commandParser.cpp ulapi.cpp controller.cpp canonicalMsg.cpp)
set(test_SOURCES test.cpp myController.cpp)
set(commandParser_SOURCES commandParserMain.cpp myController.cpp)
set(canonicalController_LIBS sqlKit pthread mysqlcppconn)

include_directories(${IPMAS_DIR}/AutoGen)
link_directories(${LIBRARY_OUTPUT_PATH})

add_library(canonicalQueue STATIC ${libcanonicalQueue_SOURCES})
add_executable(test ${test_SOURCES})
add_executable(commandParser ${commandParser_SOURCES})

#target_link_libraries(canonicalQueue ${canonicalController_LIBS})
target_link_libraries(test canonicalQueue ${canonicalController_LIBS})
target_link_libraries(commandParser canonicalQueue ${canonicalController_LIBS})
