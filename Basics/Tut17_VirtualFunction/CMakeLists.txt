cmake_minimum_required(VERSION 2.8.9)
project(Tut17_VirtualFunction)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 11) 

add_executable(test main.cpp CommissionEmployee.cpp BasePlus.cpp employee.cpp) 