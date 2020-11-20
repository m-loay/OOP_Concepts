#include <iostream>
#include <exception>
#include <memory>
#include <random>
class Test 
{
public:
	Test() { std::cout << "Test():Acquire resources" << std::endl; }
	~Test() { std::cout << "~Test():Release resources" << std::endl; }
};
// throw, catch and rethrow exception
void processMultipleTrows(int count)
{
	std::unique_ptr<Test> t(new Test);
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	//generate rondom exceptions
	std::default_random_engine eng;
	std::bernoulli_distribution dist;

	//exceptions counter, if increases upon certain number.It shall be handled from main
	int errors{};
	for (int i = 0; i < count; ++i) 
	{
		try 
		{
			std::cout << "Processing record # : " << i << " ";
			if (!dist(eng)) 
			{
				//increment exception counter when exception occirs
				++errors;
				throw std::runtime_error("Could not process the record");
			}
			std::cout << std::endl;
		}
		catch (std::runtime_error &ex) 
		{
			//handel the exception
			std::cout << "[ERROR " << ex.what() << "]" << std::endl;

			//check exception exceeds certain error to throw exception to main
			if (errors > 4) 
			{
				std::runtime_error err("Too many errors. Abandoning operation");
				ex = err;
				throw;
			}
		}
	}
}// end function throwException

int main()
{
	try 
	{
		processMultipleTrows(20);
	}
	/*
	std::exception is the base class for all standard exception classes.
	It can be used as a handler if the exception handling code is
	same for all child class exception objects.
	*/
	catch (std::exception &ex) 
	{
		std::cout << ex.what() << std::endl;
	}
}// end main