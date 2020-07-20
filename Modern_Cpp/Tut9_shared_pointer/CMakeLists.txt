cmake_minimum_required(VERSION 2.8.9)
project(Tut9_shared_pointer)
 
# #set build type to debug and C++ standard to 11
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test main.cpp Integer.cpp)