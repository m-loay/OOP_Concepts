/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>

int main()
{
	//create array for print
	int arr[5] = {1,2,3,4,5};

	//crerating standard for loop
	std::cout<<"Standard for-loop"<<std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;

	//create range based for loop by const ref(arr elements will not be modified)
	std::cout<<"Range based for-loop(Non-modifiying version)"<<std::endl;
	for(const auto &x:arr) std::cout<<x<<" ";
	std::cout<<std::endl;

	//create range based for loop by const ref(arr elements will be modified)
	std::cout<<"Range based for-loop(modifiying version)"<<std::endl;
	for(auto &x:arr) std::cout<<++x<<" ";
	std::cout<<std::endl;
	std::cout<<"Print Array after modification"<<std::endl;
	for(const auto &x:arr) std::cout<<x<<" ";
	std::cout<<std::endl;

	//internal implementation range based for loop using pointers
	std::cout<<"Print Array using internal implementation of range based for loop"<<std::endl;
	auto &&range = arr; //using forward refernce to allow using r-value and l-values
	auto beg = std::begin(arr);
	auto end = std::end(arr);
	for(;beg!=end; ++beg)
	{
		auto x = *beg;
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;
	
}
