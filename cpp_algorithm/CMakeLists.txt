cmake_minimum_required(VERSION 3.31.6)
project(exercise2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
# add_executable(exercise2 src/data_structure/queue.cpp)
add_executable(exercise2 ./src/coroutines/coroutine_lifecycle.cpp)

# add_executable(exercise2 ./src/coroutines/coroutine_is_stopped.cpp)

# add_executable(exercise2 ./src/coroutines/coroutine_rewrite.cpp)
# find_package(SDL3 CONFIG REQUIRED)
# target_link_libraries(exercise2 PRIVATE SDL3::SDL3)
