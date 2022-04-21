cmake_minimum_required(VERSION 3.20)
project(Data_Structures)
 
# #set build type to debug and C++ standard to 11
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1_linked_list 1_linked_list.cpp)
add_executable(2_linked_list_circular 2_linked_list_circular.cpp)
add_executable(3_stack 3_stack.cpp)
add_executable(4_qeue 4_qeue.cpp)
add_executable(5_stack_array 5_stack_array.cpp)
