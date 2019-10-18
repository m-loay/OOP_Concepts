cmake_minimum_required(VERSION 2.8.9)
project(Tut18_PureVirtualFunction)
 
#set build type to debug
set(CMAKE_BUILD_TYPE Debug)

add_executable(test main.cpp CommissionEmployee.cpp BasePlus.cpp employee.cpp HourlyEmployee.cpp SalariedEmployee.cpp) 