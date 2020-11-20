#include <iostream>
#include <vector>
#include <random>
#include <memory>

class A 
{
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};

class B 
{
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};

class Test1 
{
	A *pA;
	B b{};
	int* pInt;
	char* pStr;
	int* pArr;
public:
	Test1() 
	{ 
		std::cout << "Test1():Acquire resources" << std::endl;
		pA = new A;
		pInt = new int;
		throw std::runtime_error("Failed to initialize Test1");
		pStr = new char[1000];
		pArr = new int[50000];
	}
	~Test1() 
	{
		std::cout << "~Test1():Release resources" << std::endl; 
		delete pA;
		delete pInt;
		//throw std::runtime_error("Destructor Fails Test1");
		delete[]pStr;
		delete[] pArr;
	}
};

class Test2 
{
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	Test2() 
	{ 
		std::cout << "Test2():Acquire resources" << std::endl;
		pA.reset(new A);
		pInt.reset(new int);
		throw std::runtime_error("Failed to initialize Test2");
		pStr.append("Data");
		pArr={1,2,3,4,5,6};
	}
	~Test2() 
	{  
		std::cout << "~Test2():Release resources" << std::endl;
		//throw std::runtime_error("Destructor Fails Test2");
	}
};

int main() 
{
	try 
	{
		Test1 t1;
		throw std::runtime_error("Main Failed to initialize Test1");
	}
	catch (std::exception &ex) 
	{
		std::cout << ex.what() << std::endl;
	}

	try 
	{
		Test2 t2;
		throw std::runtime_error("Main Failed to initialize Test2");
	}
	catch (std::exception &ex) 
	{
		std::cout << ex.what() << std::endl;
	}
}