cmake_minimum_required(VERSION 2.8)

project(ulapi)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(src)

add_subdirectory(lib)
add_subdirectory(bin)
