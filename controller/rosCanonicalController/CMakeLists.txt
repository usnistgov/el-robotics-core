cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#to get ROS to understand that it's not in the root cmake directory
get_filename_component(CONTROLLER_DIRECTORY ${PROJECT_SOURCE_DIR} PATH)
get_filename_component(IPMAS_DIRECTORY ${CONTROLLER_DIRECTORY} PATH)

SET(controlGUI_SOURCES src/controlGUI/main.cpp src/controlGUI/mainwindow.cpp src/controlGUI/customcontrols.cpp)
SET(controlGUI_HEADERS include/controlGUI/mainwindow.h include/controlGUI/customcontrols.h)
SET(controlGUI_FORMS src/controlGUI/mainwindow.ui)

SET(rosControl_SOURCES src/rosControl/rosInf.cpp
                       src/rosControl/navigationGoal.cpp
                       src/rosControl/rosController.cpp
                       src/rosControl/robotDescription.cpp)

SET(binPickup_SOURCES src/binPickup/scanPattern.cpp src/binPickup/scanPickup.cpp)

SET(roscontroller_LIBS canonicalQueue rosControl)

#set up QT build
FIND_PACKAGE(Qt4 REQUIRED)
QT4_WRAP_CPP(controlGUI_HEADERS_MOC ${controlGUI_HEADERS})
QT4_WRAP_UI(controlGUI_FORMS_HEADERS ${controlGUI_FORMS})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_NO_KEYWORDS) #need this fix for boost

link_directories(${CONTROLLER_DIRECTORY}/canonicalQueue/lib ${IPMAS_DIRECTORY}/AutoGen/)
include_directories(${CONTROLLER_DIRECTORY}/canonicalQueue/src ${CMAKE_CURRENT_BINARY_DIR} ${IPMAS_DIRECTORY}/AutoGen)

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
