cmake_minimum_required(VERSION 3.13.4)
project(ShareIT)

set(CMAKE_CXX_STANDARD 11)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


file(GLOB_RECURSE SOURCES "src/*.cc")

add_executable(ShareIT ${SOURCES})
target_link_libraries(ShareIT pthread)