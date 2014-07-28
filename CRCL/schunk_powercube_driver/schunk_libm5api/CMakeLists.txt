# http://ros.org/doc/groovy/api/catkin/html/user_guide/supposed.html
cmake_minimum_required(VERSION 2.8.3)
project(schunk_libm5api)

find_package( Threads )

###########
## Build ##
###########

# add include search paths
include_directories(include)
#common commands for building c++ executables and libraries
add_library(m5api
  src/Device/Device.cpp
  src/Device/ProtocolDevice.cpp
  src/Device/ProtocolMessage.cpp
  src/Device/RS232Device.cpp
  src/Util/Random.cpp
  src/Util/Message.cpp
  src/Util/StopWatch.cpp
  src/Util/IOFunctions.cpp 
  src/Util/Thread.cpp
  src/M5apiw32/m5apiw32.cpp
)
set_target_properties(m5api PROPERTIES COMPILE_FLAGS "-D__LINUX__")# -DUSE_PCAN -DUSE_ESD")
target_link_libraries(m5api ${CMAKE_THREAD_LIBS_INIT})# ${catkin_LIBRARIES})

