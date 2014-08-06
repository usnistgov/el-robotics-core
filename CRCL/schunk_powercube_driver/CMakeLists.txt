cmake_minimum_required(VERSION 2.6)
project(schunk_powercube_driver)

add_subdirectory(schunk_libm5api)
include_directories(
  include
  schunk_libm5api/include
)
link_libraries(m5api)

add_executable(home_test test/home.cpp)
add_executable(enumerate_modules test/enumerate.cpp)

