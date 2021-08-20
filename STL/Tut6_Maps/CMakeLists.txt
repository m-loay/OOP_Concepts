cmake_minimum_required(VERSION 3.12)
project(Tut28_Maps)
 
#set build type to debug

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

add_executable(${PROJECT_NAME} main.cpp) 