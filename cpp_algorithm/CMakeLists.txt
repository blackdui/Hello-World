cmake_minimum_required(VERSION 3.31.6)
project(ImportStdExample LANGUAGES CXX)

# Require C++23
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Create executable
add_executable(main 
    ./src/modules/main.cpp
)

# find_package(SDL3 CONFIG REQUIRED)
# target_link_libraries(exercise2 PRIVATE SDL3::SDL3)
