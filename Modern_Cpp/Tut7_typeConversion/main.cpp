#include <iostream>
#include "Integer.h"

int main() 
{
	int a =5,b=2;

	/*Wrong Casting c-style*/
	float f1 = a/b;

	/*Correct Casting c-style*/
	float f2 = (float)a/b;

	/*Correct Casting static cast c++*/
	float f3 = static_cast<float>(a)/b;

	/*implicit conversion between basic type --> user defined type*/
	Integer i = 7;

	/*explicit conversion between basic defined type --> basic type*/
	int ix = i;

	std::cout<<"[Wrong Casting c-style]f = 5/2 --> "<<f1<<std::endl;
	std::cout<<"[Correct Casting c-style]f = 5/2 --> "<<f2<<std::endl;
	std::cout<<"[Correct Casting static cast c++]f = 5/2 --> "<<f3<<std::endl;
	std::cout<<"[implicit conversion between basic type --> user defined type] --> "
	         <<i.GetValue()<<std::endl;
	std::cout<<"[explicit conversion between basic defined type --> basic type] --> "
	         <<ix<<std::endl;
	return 0;
}