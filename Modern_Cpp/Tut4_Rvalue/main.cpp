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
	std::cout << "x = " << x<<std::endl; 
}

//Accepts l-value (constant refernce to variable) 
// and R-values if Print(int &&x) not exist
void Print(const int &x) 
{
	std::cout << "Print(const int&)" << std::endl;
	std::cout << "x = " << x<<std::endl; 
}

//Accepts R-value (constant refernce to variable)
void Print(int &&x) 
{
	std::cout << "Print(int &&)" << std::endl;
    std::cout << "x = " << x<<std::endl; 
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
	std::cout << "input l-value x" << std::endl;
	Print(x);
	
	//Add returns a temporary (r-value)
	std::cout << "int &&rv = Add(3,5) ;" << std::endl;
	int &&rv = Add(3,5) ;
	std::cout << "rv = " << rv<<std::endl; 
	

	//Binds to function that accepts a temporary, i.e. r-value reference
	// comment function Print(int &&), the input argument 3(R-value) will bind to L-value
	//only when the refernce is constant in that case function Print(const int&) will be called.
	std::cout << "Print(3)" << std::endl;
	Print(3);

	//Assign variable x to r-value gives compilation error
	// int &&r3 = x;

	return 0;
}

