cmake_minimum_required(VERSION 3.12)
project(cppCourse)
#set build type to debug

set (CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Basics/Tut1_pointers_and_refParamters)
add_subdirectory(Basics/Tut2_Const_ref_Vs_ref)
add_subdirectory(Basics/Tut3_DefaultArguments_FunctionTemp)
add_subdirectory(Basics/Tut4_CallingConstructorDestructor)
add_subdirectory(Basics/Tut5_ConstObj_ConstMembers)
add_subdirectory(Basics/Tut6_MemberInitializer)
add_subdirectory(Basics/Tut7_Compostion_oop)

