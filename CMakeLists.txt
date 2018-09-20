cmake_minimum_required(VERSION 3.1.0)

project(cmake-qtcore-example)

find_package(Qt5Core CONFIG REQUIRED)

SET(SOURCES main.cpp)

add_executable(cmake-qtcore-example ${SOURCES})
target_link_libraries(cmake-qtcore-example Qt5::Core)

