cmake_minimum_required(VERSION 4.1)
project(exercise2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
# add_executable(exercise2 src/data_structure/queue.cpp)
add_executable(exercise2 src/stl/queue.cpp)

# find_package(SDL3 CONFIG REQUIRED)
# target_link_libraries(exercise2 PRIVATE SDL3::SDL3)
