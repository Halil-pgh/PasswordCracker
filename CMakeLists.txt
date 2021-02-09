cmake_minimum_required(VERSION 3.1)

project(Default)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${INCLUDE_DIR})

file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})