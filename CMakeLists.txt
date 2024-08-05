cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

project("ShareIT")

# find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_custom_target(
    run_shell_script
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Запуск скрипта..."
    COMMAND bash ../check_lib.sh
    DEPENDS ${main}
)

file(GLOB SRC "src/*")
# file(GLOB GUI_SRC "GUI/src/*")
# file(GLOB HEADERS_TO_MOC GUI/include/*.h)

# find_package(Qt5Widgets REQUIRED)

# find_package(Qt5Core REQUIRED)

add_executable(main ${SRC})
                    # ${GUI_SRC})

add_dependencies(main run_shell_script)

target_include_directories(main PRIVATE "include" )
                                        # "GUI/include" )
# target_link_libraries(main PRIVATE Qt5::Widgets)
# target_link_libraries(main Qt5::Widgets Qt5::Core)
target_link_libraries(main ${Boost_LIBRARIES} pthread)