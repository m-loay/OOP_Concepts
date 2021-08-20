cmake_minimum_required(VERSION 3.12)
project(Tut5_HandlingExcep_bad_alloc)
 
#set build type to debug

set (CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp) 