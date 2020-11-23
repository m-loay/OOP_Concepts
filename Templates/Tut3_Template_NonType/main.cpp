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
 *  Print                                                *
 ********************************************************************************/
//Non-type template parameter
template<int size>
void Print() 
{
	char buffer[size];
	std::cout << size << std::endl;
}

/*******************************************************************************
 *  Sum                                                                        *
 ********************************************************************************/
template<typename T>
T Sum(T*parr, int size)
{
	T sum{};
	for (int i = 0; i < size; ++i) 
	{
		sum += parr[i];
	}
	return sum;
}
//Size is implicitly calculated in non-type template argument
template<typename T,int size>
T Sum(T (&arr)[size]) 
{
	T sum{};
	for (int i = 0; i < size; ++i) 
	{
		sum += arr[i];
	}
	return sum;
}


/*******************************************************************************
 *  Main                                                        *
 *******************************************************************************/
int main() 
{
	Print<3>();
	int arr[]{ 3,1,9,7 };
	OPERATION(int sum = Sum(arr,4));
	std::cout << sum << std::endl; 

	int (&arr_ref)[4] = arr;
	OPERATION(sum = Sum(arr_ref));
	std::cout << sum << std::endl; 
	return 0;
}