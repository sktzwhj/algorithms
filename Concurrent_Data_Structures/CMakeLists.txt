cmake_minimum_required(VERSION 3.7)
project(leetcode_debug)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(leetcode_debug ${SOURCE_FILES})
target_link_libraries(leetcode_debug libpthread.so)