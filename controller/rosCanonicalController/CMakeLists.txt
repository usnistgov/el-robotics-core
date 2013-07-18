cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

SET(controlGUI_SOURCES src/controlGUI/main.cpp src/controlGUI/mainwindow.cpp)
SET(controlGUI_HEADERS include/controlGUI/mainwindow.h)
SET(controlGUI_FORMS src/controlGUI/mainwindow.ui)

SET(rosControl_SOURCES src/rosControl/rosInf.cpp src/rosControl/navigationGoal.cpp src/rosControl/rosController.cpp)
SET(rosControl_HEADERS src/rosControl/rosInf.hh src/rosControl/navigationGoal.hh)

SET(binPickup_SOURCES src/binPickup/scanPattern.cpp src/binPickup/scanPickup.cpp)

SET(roscontroller_LIBS Controller rosControl)

#set up QT build
FIND_PACKAGE(Qt4 REQUIRED)
QT4_WRAP_CPP(controlGUI_HEADERS_MOC ${controlGUI_HEADERS})
QT4_WRAP_UI(controlGUI_FORMS_HEADERS ${controlGUI_FORMS})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_NO_KEYWORDS) #need this fix for boost

link_directories(~/ipmas/controller) #change this line to point to the ipmas directory
link_directories(~/ipmas/AutoGen) #change this line to point to the ipmas directory

rosbuild_add_library(rosControl STATIC ${rosControl_SOURCES})

rosbuild_add_executable(rosCanonicalController 
                      src/canonicalController.cpp)

rosbuild_add_executable(binPickup
                      ${binPickup_SOURCES})

ADD_EXECUTABLE(controlGUI
  ${controlGUI_SOURCES}
  ${controlGUI_HEADERS_MOC}
  ${controlGUI_FORMS_HEADERS})							

target_link_libraries(rosControl pthread sqlKit mysqlcppconn)
target_link_libraries(rosCanonicalController ${roscontroller_LIBS})
target_link_libraries(binPickup ${roscontroller_LIBS})
target_link_libraries(controlGUI ${roscontroller_LIBS} ${QT_LIBRARIES})

include_directories(../ ../../AutoGen/ ${CMAKE_BINARY_DIR})
