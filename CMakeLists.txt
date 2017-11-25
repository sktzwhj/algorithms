cmake_minimum_required(VERSION 3.5)   # CMake version check
project(leetcode)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
set(ARRAY_SRC ./Array)
set(SOURCE_FILES ${ARRAY_SRC}/Q66_Plus_One.cpp)            # Add main.cpp file of project root directory as source file
add_executable(Q66 ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
