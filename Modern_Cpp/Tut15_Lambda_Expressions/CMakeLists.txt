cmake_minimum_required(VERSION 3.12)
project(Tut15_Lambda_Expressions)
 
# #set build type to debug and C++ standard to 11

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)