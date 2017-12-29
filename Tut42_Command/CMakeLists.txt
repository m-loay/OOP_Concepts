cmake_minimum_required(VERSION 2.8.9)
project(Tut42_Command)
 
#set build type to debug
set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

add_executable(test main.cpp) 