#include <iostream>
#include <vector>
#include <random>
#include <memory>

class Test 
{
public:
	Test() { std::cout << "Test():Acquire resources" << std::endl; }
	~Test() { std::cout << "~Test():Release resources" << std::endl; }
};

void useExceptionHandlingusingLocalObject(int count)
{
	//create object of class test
	Test t;

	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	int *p = new int[count];
	int *pArray = (int*)malloc(count * sizeof(int));

	//Process the records
	for (int i = 0; i < count; ++i) 
	{
		pArray[i] = i;
	}

	//Unreachable code in case of an exception
	//this will cause a memory leak
	free(pArray);
	delete[] p;
}

void useExceptionHandlingusingRawPointers(int count)
{
	//create object of class test
	Test *t = new Test;

	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	int *p = new int[count];
	int *pArray = (int*)malloc(count * sizeof(int));

	//Process the records
	for (int i = 0; i < count; ++i) 
	{
		pArray[i] = i;
	}

	//Unreachable code in case of an exception
	//this will cause a memory leak
	free(pArray);
	delete[] p;
	delete t;
}

void useExceptionHandlingusingSmartPointers(int count)
{
	std::unique_ptr<Test> t(new Test);
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	std::vector<int> p;
	p.reserve(count);
	std::vector<int> records;
	records.reserve(count);
	//Process the records
	for (int i = 0; i < count; ++i) 
	{
		records.push_back(i);
	}
}

int main() 
{
	try
	{
		std::cout << "=========Calling useExceptionHandlingusingLocalObject: ========="<< std::endl; 
		useExceptionHandlingusingLocalObject(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "=========Calling useExceptionHandlingusingRawPointers: ========="<< std::endl; 
		useExceptionHandlingusingRawPointers(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "=========Calling useExceptionHandlingusingSmartPointers: ========="<< std::endl; 
		useExceptionHandlingusingSmartPointers(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}