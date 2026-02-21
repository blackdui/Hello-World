cmake_minimum_required(VERSION 3.31.6)
project(cpp_crash CXX)
add_executable(main src/inheritance.cpp)
target_include_directories(main PRIVATE include)
