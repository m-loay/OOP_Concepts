#include <iostream>

/*******************************************************************************
 *  Max Template Function                                                      *
 *******************************************************************************/
template<typename T>
T Max(T x, T y) 
{
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}
//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specialization
template<> const char * Max<const char*>(const char *x, const char *y) 
{
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

/*******************************************************************************
 *  Print Template Function                                                    *
 *******************************************************************************/
//Non-type template parameter
template<int size>
void Print() 
{
	char buffer[size];
	std::cout << size << std::endl;
}

/*******************************************************************************
 *  Sum Template class                                                         *
 *******************************************************************************/
//Requires size as explicit argument
template<typename T>
T Sum(T*arr, int size)
{
	T sum{};
	std::cout<<"Sum(T*parr, int size)"<<std::endl;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
//Size is implicitly calculated in non-type template argument
template<typename T,int size>
T Sum(T (&arr)[size]) 
{
	T sum{};
	std::cout<<"Sum(T (&arr)[size])"<<std::endl;
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
	//Test max Function

	//use max float version and cast the 1st operand
	Max(static_cast<float>(3), 5.5f);

	//Override compiler's deduction process
	Max<double>(3, 6.2);

	//Causes implicit instantiation of Max<int>
	int(*pfn)(int, int) = Max;
	const char *b{ "B" };
	const char *a{ "A" };
	auto s = Max(a, b);
	std::cout << s << std::endl;

	//Test print

	//Non-type template parameter
	Print<3>();

	//Test Sum Template class  

	int arr[]{ 3,1,9,7 };

	int sum = Sum(arr);
	std::cout << sum << std::endl;
	sum = Sum(arr,4);
	std::cout << sum << std::endl;  

	return 0;
}