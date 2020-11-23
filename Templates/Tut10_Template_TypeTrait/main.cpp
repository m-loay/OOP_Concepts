#include <iostream>
#include <type_traits>
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x
template <typename T>
T divide( T a, T b)
{
	T output;
	if(std::is_floating_point<T>::value == false)
	{
		output = 0;
		std::cout<<"Only floating points is accepted"<<std::endl;
	}
	else
	{
		output = a/b;
	}
	return output;
}

int main() 
{
	float out;
	OPERATION(out = divide(8.2,2.2));
	std::cout<<"result = "<<out<<std::endl;

	OPERATION(out = divide(2,3));
	std::cout<<"result = "<<out<<std::endl;

	return 0;
}
