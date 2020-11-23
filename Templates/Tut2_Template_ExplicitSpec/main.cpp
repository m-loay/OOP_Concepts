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
//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specialization
template<> const char * Max<const char*>(const char *x, const char *y) 
{
	std::cout << "Max<const char*>()" << std::endl;
	const char *z = strcmp(x, y) > 0 ? x : y;
	return z;
}


/*******************************************************************************
 *  Main                                                        *
 *******************************************************************************/
int main() 
{
	OPERATION(auto s = Max("A", "B"));
	std::cout << s << std::endl; 
	return 0;
}