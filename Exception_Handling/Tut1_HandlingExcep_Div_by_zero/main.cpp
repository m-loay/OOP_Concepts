#include <iostream>
#include <vector>
#include <random>
#include <memory>
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

void useExceptionHandlingFunctionLevel(void)
{
	//user input
	int num1(10) , num2(0);

	//output
	double result;

	//output numbers
	std::cout<<num1<<" / "<<num2<<" = "<<std::endl;

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

	//output numbers
	num1 = 10;
	num2 = 5;
	std::cout<<num1<<" / "<<num2<<" = "<<std::endl;

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

int main() 
{
	try
	{
		std::cout << "=========Calling useExceptionHandlingFunctionLevel: ========="<< std::endl; 
		useExceptionHandlingFunctionLevel();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}