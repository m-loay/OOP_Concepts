
#include <iostream>
#include <stdexcept>

// function3 throws runtime error
void function3()
{
 	std::cout << "In function 3" << std::endl;
	 // no try block, stack unwinding occurs, return control to function2
 	throw std::runtime_error( "runtime_error in function3" ); // no print
} // end function3

// function2 invokes function3
void function2()
{
	std::cout << "function3 is called inside function2" << std::endl;
	function3(); // stack unwinding occurs, return control to function1
} // end function2

// function1 invokes function2
void function1()
{
	std::cout << "function2 is called inside function1" << std::endl;
	function2(); // stack unwinding occurs, return control to main
} // end function1

// demonstrate stack unwinding
int main()
{
// invoke function1
	try
	{
		std::cout << "function1 is called inside main" << std::endl;
		function1(); // call function1 which throws runtime_error
	} // end try
	catch ( std::runtime_error &error ) // handle runtime error
	{
		std::cout << "Exception occurred: " <<std::endl;
		std::cout << "Exception handled in main" << std::endl;
	} // end catch
} // end main