cmake_minimum_required(VERSION 2.8.9)
project(Tut14_Inheritance_UsingPrivateData)
 
#set build type to debug
set(CMAKE_BUILD_TYPE Debug)

add_executable(test main.cpp CommissionEmployee.cpp BasePlus.cpp) 