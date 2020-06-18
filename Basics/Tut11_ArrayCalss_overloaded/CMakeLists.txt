cmake_minimum_required(VERSION 2.8.9)
project(Tut11_ArrayCalss_overloaded)
 
# #set build type to debug and C++ standard to 11
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 11)  

add_executable(overloaded main.cpp Array.cpp)