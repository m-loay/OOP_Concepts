#include <iostream>
#include <memory>
#include"Integer.h"
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x

void Display(Integer *p);
void Display(std::unique_ptr<Integer> &p);
Integer * GetPointer(int value);
void operateNormalPointer(int value);
void operateSmartPointer(int value);

int	main()
{
	//compare between creating smart pointer and class-like smar pointer
	OPERATION(operateNormalPointer(5));
	OPERATION(operateSmartPointer(5));
	return 0;
}

//Dispaly function . input:pointer to object type Integer
void Display(Integer *p)
{
	std::cout<< "Display(Integer *p)" << std::endl;
	if(!p)
	{
		return;
	}
	std::cout<< p->GetValue() << std::endl;
}

//Dispaly function . input:unique pointer to object type Integer
void Display(std::unique_ptr<Integer> &p)
{
	std::cout<< "Display(std::unique_ptr<Integer> &p)" << std::endl;
	if(!p)
	{
		return;
	}
	std::cout<< p->GetValue() << std::endl;
}

//GetPointer function . creating factory from Integer.
Integer * GetPointer(int value)
{
	Integer *p = new Integer{value};
	return p;
}

//operateNormalPointer function. Using normal pointer construct/re-construct pointers
void operateNormalPointer(int value)
{
	//create new normal pointer 
	Integer *p = GetPointer(value);
	if(!p)
	{
		p = new Integer{value};
	}
	//set the value of the normal pointer
	p->SetValue(100);

	//Display the value of normal pointer
	Display(p);

	//Destroy the value of normal pointer
	delete p;
	p = nullptr;

	//re-construct normal pointer
	p =  GetPointer(10);

	//set the value of the normal pointer
	*p = __LINE__;

	//Display the value of normal pointer
	Display(p);

	//Destroy the value of normal pointer
	delete p;
	p = nullptr;
}

//operateSmartPointer function. Using unique pointer construct/re-construct pointers
void operateSmartPointer(int value)
{
	//create new unique pointer 
	std::unique_ptr<Integer> p {GetPointer(value)};
	if(!p)
	{
		p.reset(GetPointer(value));//create a new pointer
	}

	//set the value of the unique pointer
	p->SetValue(100);

	//Move the unipue pointer(it will be destroyed) to disply the value
	//Unique pointer doesnt have copy constructor
	Display(std::move(p));

	//set it to nuullptr
	p = nullptr;

	//re-construct uniqe pointer
	p.reset(GetPointer(value));

	//set the value of the unique pointer
	p->SetValue( __LINE__);


	//Display the value of unique pointer (seny by refernce it wont destroyed)
	Display(p);
}

