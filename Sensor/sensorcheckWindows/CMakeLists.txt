# To use this file:
# 1. Install CMake
# 2. Create a "build" directory inside the "Sensor" folder
# 3. Place this file in the "Sensor" folder
# 4. Uncomment or fix the comments in this file
# 5. Run "cmake ." in the "Sensor" folder
# 6. Hopefully, you've generated a configured vc++ project that compiles. You may still need to manually add the location of the mysqlcppconn library.

cmake_minimum_required(VERSION 2.4.6)
PROJECT(sensorcheck)

FIND_PACKAGE(Qt4 REQUIRED)


set(sensorcheck_HEADERS include/gui.h)
QT4_WRAP_CPP(sensorcheck_HEADERS_MOC ${sensorcheck_HEADERS})

set(MYSQL_DIRECTORY C:/Program\ Files\ \(x86\)/MySQL/MySQL\ Connector\ C++\ 1.1.3/)
set(IPMAS_DIRECTORY C:/ipmas)

INCLUDE(${QT_USE_FILE})

set(sensorcheck_SOURCES src/main.cpp
												src/parseUtils.cpp
												src/win32_ulapi.c
												src/usarTruth.cpp
												src/gui.cpp
												${IPMAS_DIRECTORY}/objectGen/src/recurseLocation.cpp
												${IPMAS_DIRECTORY}/objectGen/src/partModel.cpp
												${IPMAS_DIRECTORY}/objectGen/src/genericModel.cpp)

#may need to get rid of "pthread", not sure																
set(sensorcheck_LIBS sqlKit mysqlcppconn wsock32)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} include ${IPMAS_DIRECTORY}/AutoGen ${IPMAS_DIRECTORY}/objectGen/include ${MYSQL_DIRECTORY}/include C:/Program\ Files\ \(x86\)/boost/boost_1_50 C:/USARTRUTH)
add_definitions(${QT_DEFINITIONS})
link_directories(C:/Users/GGM/Documents/Visual\ Studio\ 2012/Projects/StaticLibrary/Debug/ ${MYSQL_DIRECTORY}/lib/opt)

add_executable(sensorcheck ${sensorcheck_SOURCES} ${sensorcheck_HEADERS_MOC})
target_link_libraries(sensorcheck ${sensorcheck_LIBS} ${QT_LIBRARIES})
