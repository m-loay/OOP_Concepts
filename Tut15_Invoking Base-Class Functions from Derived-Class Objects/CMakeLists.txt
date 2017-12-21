cmake_minimum_required(VERSION 2.8.9)
project(ut15_Invoking_BaseClassFunctions_fromDerived-Class)
 
#Bring the headers, such as Student.h into the project
#include_directories()
 
#Can manually add the sources using the set command as follows:
#set(SOURCES main.cpp TimeBase.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

#set build type to debug
set(CMAKE_BUILD_TYPE Debug)


add_executable(test main.cpp CommissionEmployee.cpp BasePlus.cpp) 