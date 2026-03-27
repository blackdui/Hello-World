cmake_minimum_required(VERSION 3.31.6)

project(c_crash)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -pg -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main src/whatever.c)

