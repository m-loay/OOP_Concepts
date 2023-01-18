cmake_minimum_required(VERSION 3.12)
project(cppCourse)
 

set (CMAKE_CXX_STANDARD 20) 
set(CMAKE_BUILD_TYPE DEBUG)

#basics
add_subdirectory(Basics/Tut1_pointers_and_refParamters)
add_subdirectory(Basics/Tut2_Const_ref_Vs_ref)
add_subdirectory(Basics/Tut3_DefaultArguments_FunctionTemp)
add_subdirectory(Basics/Tut4_CallingConstructorDestructor)
add_subdirectory(Basics/Tut5_ConstObj_ConstMembers)
add_subdirectory(Basics/Tut6_MemberInitializer)
add_subdirectory(Basics/Tut7_Compostion_oop)
add_subdirectory(Basics/Tut8_Cascaded_member_function_Call_thisPointer)
add_subdirectory(Basics/Tut9_static_member)
add_subdirectory(Basics/Tut10_Overloading_Stream_Insertion_and_Stream)
add_subdirectory(Basics/Tut11_math_overload)
add_subdirectory(Basics/Tut12_ArrayCalss_overloaded)
add_subdirectory(Basics/Tut13_Inheritance_Version1_Using_protected_data)
add_subdirectory(Basics/Tut14_Inheritance_UsingPrivateData)
add_subdirectory(Basics/Tut15_Invoking_BaseClassFunctions_fromDerivedClass)
add_subdirectory(Basics/Tut16_Derived_ClassMemberFunction_CallsViaBaseClassPointersClass)
add_subdirectory(Basics/Tut17_VirtualFunction)
add_subdirectory(Basics/Tut18_PureVirtualFunction)
add_subdirectory(Basics/Tut19_StackTemplate)
add_subdirectory(Basics/Tut20_NameSpace)
add_subdirectory(Basics/Tut21_MemManagement)
add_subdirectory(Basics/Tut22_convert_types)
add_subdirectory(Basics/Tut23_ArrayClassModern)

##Modern_Cpp
#add_subdirectory(Modern_Cpp/Tut1_Uniform_Initialization)
#add_subdirectory(Modern_Cpp/Tut2_Range_based_for_loop)
#add_subdirectory(Modern_Cpp/Tut3_Delegated_Constructor)
#add_subdirectory(Modern_Cpp/Tut4_Rvalue)
#add_subdirectory(Modern_Cpp/Tut5_Move_Semantics)
#add_subdirectory(Modern_Cpp/Tut6_smartpointers)
#add_subdirectory(Modern_Cpp/Tut7_typeConversion)
#add_subdirectory(Modern_Cpp/Tut8_Unique_pointer)
#add_subdirectory(Modern_Cpp/Tut9_shared_pointer)
#add_subdirectory(Modern_Cpp/Tut10_weak_pointer)
#add_subdirectory(Modern_Cpp/Tut11_Enums)
#add_subdirectory(Modern_Cpp/Tut12_constexpr)
#add_subdirectory(Modern_Cpp/Tut13_IntialzerList)
#add_subdirectory(Modern_Cpp/Tut14_FunctionObjects)
#add_subdirectory(Modern_Cpp/Tut15_Lambda_Expressions)
#
##Data Structure
#add_subdirectory(Data_Structures/Tut1_linked_list)
#add_subdirectory(Data_Structures/Tut2_linked_list_circular)
#add_subdirectory(Data_Structures/Tut3_stack)
#add_subdirectory(Data_Structures/Tut4_qeue)
#add_subdirectory(Data_Structures/Tut5_stack_array)
#add_subdirectory(Data_Structures/Tut6_tree)
#
## STL
#add_subdirectory(STL/Tut1_Vector)
#add_subdirectory(STL/Tut2_ForwardList)
#add_subdirectory(STL/Tut3_Set)
#add_subdirectory(STL/Tut4_Maps)
#add_subdirectory(STL/Tut5_Algorithms)














