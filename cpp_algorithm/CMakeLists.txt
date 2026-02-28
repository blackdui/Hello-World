cmake_minimum_required(VERSION 3.31.6)
project(cpp_algorithm CXX)

set(CMAKE_CXX_STANDARD 23)
add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include)
