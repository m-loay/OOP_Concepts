#include <iostream>

//Returns r-value
int Add(int x, int y) 
{
	return x + y;
}

//Return l-value
int & Transform(int &x) 
{
	x *= x;
	return x;
}

//Accepts l-value (refernce to variable)
void Print(int &x) 
{
	std::cout << "Print(int&)" << std::endl; 
}

//Accepts l-value (constant refernce to variable)
void Print(const int &x) 
{
	std::cout << "Print(const int&)" << std::endl;
}

//Accepts R-value (constant refernce to variable)
void Print(int &&x) 
{
	std::cout << "Print(int &&)" << std::endl;
}

int main() 
{
	//x is lvalue
	int x = 10;
	
	//ref is l-value reference
	int &ref = x ;

	//Transform returns an l-value
	int &ref2 = Transform(x) ;
	//Binds to function that accepts l-value reference
	Print(x);
	
	//rv is r-value reference
	int &&rv = 8 ;
	
	//Add returns a temporary (r-value)
	int &&rv2 = Add(3,5) ;

	//Binds to function that accepts a temporary, i.e. r-value reference
	// comment function Print(int &&), the input argument 3(R-value) will bind to L-value
	//only when the refernce is constant in that case function Print(const int&) will be called.
	Print(3);

	//Assign variable x to r-value gives compilation error
	// int &&r3 = x;

	return 0;
}

