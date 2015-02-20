cmake_minimum_required(VERSION 2.8)

project(ulapi)

catkin_package(
  INCLUDE_DIRS src
  LIBRARIES ulapi dl pthread
)

add_subdirectory(lib)
add_subdirectory(bin)
