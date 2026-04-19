cmake_minimum_required(VERSION 3.31.6)
project(exercise2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
add_executable(exercise2 ./src/ranges/function_composition6.cpp)
# find_package(SDL3 CONFIG REQUIRED)
# target_link_libraries(exercise2 PRIVATE SDL3::SDL3)
