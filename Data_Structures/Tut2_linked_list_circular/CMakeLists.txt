cmake_minimum_required(VERSION 3.12)
project(Tut2_linked_list_circular)

#set build type to debug

set (CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} 2_linked_list_circular.cpp)