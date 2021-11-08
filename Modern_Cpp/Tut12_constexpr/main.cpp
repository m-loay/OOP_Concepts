#include <iostream>

constexpr int GetNumber() 
{
	return 42;
}
constexpr int Add(int x, int y) 
{
	return x + y;
}
constexpr int Max(int x, int y) 
{
	//Needs C++14 compiler
	//if (x > y)
	//	return x;
	//return y;
	return x > y ? x : y;
}

int main() 
{
	//Behaves as a constexpr function
	constexpr int i = GetNumber();
	int arr[i];

	//Behaves as a constexpr function
	const int j = GetNumber();
	int arr1[j];

	//Behaves as a normal function
	int x = GetNumber();

	//Error x is not constexpr
	//constexpr int sum = Add(x, 5);

	//Behaves as a normal function. 
	int sum2 = Add(3, 5);

	return 0;
}