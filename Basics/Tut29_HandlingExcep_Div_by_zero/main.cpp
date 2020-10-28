#include <iostream>
#include <vector>
#include "DivideByZeroException.h"

// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs
double quotient (int numerator , int denominator)
{
	// throw DivideByZeroException if trying to divide by zero
	if(denominator == 0)
	{
		throw DivideByZeroException();
	}

	//return divion results
	return static_cast<double>(numerator)/denominator;
}

int main() 
{
	//user input
	int num1 , num2;

	//output
	double result;

	std::cout<<"Enter two intgers"<<std::endl;

	//enable user to enter inputs
	while(std::cin >> num1>> num2)
	{
		// try block contains code that might throw exception
		// and code that will not execute if an exception occurs
		try
		{
			result = quotient( num1, num2);
			std::cout << "The quotient is: " << result << std::endl; 
		}
		catch(DivideByZeroException &divideByZeroException)
		{
			std::cout << "Exception occurred: "<< divideByZeroException.what() << std::endl;
		}
	}
}