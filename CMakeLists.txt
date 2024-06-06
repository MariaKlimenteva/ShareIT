cmake_minimum_required(VERSION 3.13.4)
project(ShareIT)

set(CMAKE_CXX_STANDARD 11)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# file(GLOB_RECURSE SOURCES "src/*.cc")
# Находим библиотеки Boost
find_package(Boost COMPONENTS asio REQUIRED)

# Добавляем файлы исходного кода
add_executable(sender sender.cc)
add_executable(receiver receiver.cc)

# Указываем зависимости
target_link_libraries(sender ${Boost_LIBRARIES} pthread)
target_link_libraries(receiver ${Boost_LIBRARIES} pthread)
# add_executable(ShareIT ${SOURCES})
# target_link_libraries(ShareIT pthread)