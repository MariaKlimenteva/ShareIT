cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project("ShareIT")

file(GLOB SRC "src/*")
add_executable(main ${SRC})

target_link_libraries(main ${Boost_LIBRARIES} pthread)
target_include_directories(main PRIVATE "include")