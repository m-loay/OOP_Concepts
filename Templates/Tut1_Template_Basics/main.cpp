#include <iostream>
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x
/*******************************************************************************
 *  Max Template Function                                                      *
 *******************************************************************************/
template<typename T>
T Max(T x, T y) 
{
	std::cout << typeid(T).name() << std::endl;
	T z = x > y ? x : y;
	std::cout << "Answer = "<<z<< std::endl;
	return z;
}
//Explicit Instantiation(it will placed in assembly even if its not invoced in code).
template char Max(char x, char y);

/*******************************************************************************
 *  Main                                                        *
 *******************************************************************************/
int main() 
{
	//Test max Function

	//use max float version and cast the 1st operand
	OPERATION(Max(static_cast<float>(3), 5.5f));

	//Override compiler's deduction process
	OPERATION(Max<double>(3, 6.2));

	return 0;
}