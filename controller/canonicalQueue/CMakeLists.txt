cmake_minimum_required(VERSION 2.4.6)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(canonicalQueue_SOURCES src/commandParser.cpp src/ulapi.cpp src/controller.cpp src/canonicalMsg.cpp)
set(test_SOURCES src/test.cpp src/myController.cpp)
set(commandParser_SOURCES src/commandParserMain.cpp src/myController.cpp)
set(canonicalController_LIBS sqlKit pthread mysqlcppconn)

include_directories(${IPMAS_DIRECTORY}/AutoGen)
link_directories(${LIBRARY_OUTPUT_PATH} ${IPMAS_DIRECTORY}/AutoGen)

add_library(canonicalQueue STATIC ${canonicalQueue_SOURCES})
add_executable(test ${test_SOURCES})
add_executable(commandParser ${commandParser_SOURCES})

target_link_libraries(canonicalQueue ${canonicalController_LIBS})
target_link_libraries(test canonicalQueue ${canonicalController_LIBS})
target_link_libraries(commandParser canonicalQueue ${canonicalController_LIBS})
