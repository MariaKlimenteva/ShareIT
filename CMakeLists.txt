cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project("ShareIT")

add_custom_target(
    run_shell_script
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Запуск скрипта..."
    COMMAND bash ../check_lib.sh
    DEPENDS ${main}
)

file(GLOB SRC "src/*")
add_executable(main ${SRC})
add_dependencies(main run_shell_script)

target_link_libraries(main ${Boost_LIBRARIES} pthread)
target_include_directories(main PRIVATE "include")