cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

project("ShareIT")
# cmake_minimum_required(VERSION 3.5)

# project(Shareit LANGUAGES CXX)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_custom_target(
    run_shell_script
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Запуск скрипта..."
    COMMAND bash ../check_lib.sh
    DEPENDS ${main}
)

file(GLOB SRC "src/*")
file(GLOB GUI_SRC "GUI/src/*")
file(GLOB HEADERS_TO_MOC GUI/include/*.h)

find_package(Qt5Widgets REQUIRED)

find_package(Qt5Core REQUIRED)

add_executable(main ${SRC}
                    ${GUI_SRC})
# if(ANDROID)
#   add_library(Shareit SHARED
#     main.cpp
#     mainwindow.cpp
#     mainwindow.h
#   )
# else()
#   add_executable(Shareit
#     main.cpp
#     mainwindow.cpp
#     mainwindow.h
#   )
# endif()
add_dependencies(main run_shell_script)

# qt5_use_modules(main Widgets)
# qt5_wrap_cpp(src/main.cpp GUI/src/mainwindow.cpp GUI/include/mainwindow.h)
# qt5_wrap_cpp(GUI/src/mainwindow.cpp GUI/include/mainwindow.h)

# find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

target_include_directories(main PRIVATE "include" 
                                        "GUI/include" )
# target_link_libraries(main PRIVATE Qt5::Widgets)
# target_link_libraries(main Qt5::Widgets Qt5::Core)
target_link_libraries(main ${Boost_LIBRARIES} pthread)