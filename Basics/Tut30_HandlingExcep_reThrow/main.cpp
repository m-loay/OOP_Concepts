#include <iostream>
#include <exception>

// throw, catch and rethrow exception
void throwException()
{
	// throw exception and catch it immediately
	try
	{
		std::cout << " Function throwException throws an exception\n";
		throw std::exception(); // generate exception
	} // end try
	catch(std::exception &)
	{
		std::cout << " Exception handled in function throwException"
		<< "\n Function throwException rethrows exception";
	} // end catch
	std::cout << "This also should not print\n";
}// end function throwException

int main()
{
	// throw exception
	try
	{
		std::cout << "\nmain invokes function throwException\n";
		throwException();
		std::cout << "This should not print\n";
	} // end try
	catch ( std::exception & ) // handle exception
	{
		std::cout << "\n\nException handled in main\n";
	} // end catch
	std::cout << "Program control continues after catch in main\n";
}