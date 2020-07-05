/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>
int main()
{
	//Use new to allocate a scalr varialble and initilize it.
	int *p_var = new int(5);
	std::cout<<"Value of p_var = "<<*p_var<<std::endl;
	delete p_var;
	p_var = nullptr; // if this line removed , then the program will crash.
	delete p_var;

	//Use new to allocate a aray varialble and initilize it.
	int *p_arr = new int[5]{1,2,3,4,5};
	std::cout<<"Printing Array"<<std::endl; 
	for (size_t i = 0; i < 5; i++)
	{
		std::cout<<p_arr[i]<<" ";
	}
	std::cout<<std::endl;
	delete p_arr;
	p_arr = nullptr; // if this line removed , then the program will crash.
	delete p_arr;
}
