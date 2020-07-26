#include "Integer.h"
#include <iostream>

int main() 
{
	/*Initialization*/
	Integer a(1), b(3);

	/*Overload operator +*/
	Integer sum1 =a+b;
	std::cout<<"Overload a(1) + b(3)"<<std::endl;
	std::cout<<"sum1 = "<<sum1.GetValue()<<std::endl;

	/*Overload ++d*/
	++sum1;
	std::cout<<"Overload ++d"<<std::endl;
	std::cout<<"sum1 = "<<sum1.GetValue()<<std::endl;
	
	/*Overload d++*/
	std::cout<<"sum1(post-increment) = "<<sum1++.GetValue()<<std::endl;
	std::cout<<"sum1(After post-increment) = "<<sum1.GetValue()<<std::endl;

	/*Overload ==*/
	if(a == b)
	{
		std::cout<<"Same(Overload ==)"<<std::endl;
	}
	else
	{
		std::cout<<"Not same(Overload ==)"<<std::endl;
	}

	/*Overload = */
	Integer sum2 = sum1;
	std::cout<<"*Overload ="<<std::endl;
	std::cout<<"sum1 = "<<sum1.GetValue()<<std::endl;
	std::cout<<"sum2 = "<<sum2.GetValue()<<std::endl;

	Integer c = a+3;
	std::cout<<"Overload c = a+3 --> c.operator+(3)"<<std::endl;
	std::cout<<"sum1 = "<<c.GetValue()<<std::endl;
	
	return 0;
}