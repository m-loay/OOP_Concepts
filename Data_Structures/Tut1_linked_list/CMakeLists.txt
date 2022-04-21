cmake_minimum_required(VERSION 3.12)
project(Tut1_linked_list)

#set build type to debug

set (CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} 1_linked_list.cpp 1_linked_list.cpp)