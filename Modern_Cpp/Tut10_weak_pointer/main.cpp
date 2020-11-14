#include <iostream>
#include <memory>
#include "printer.h"
#include "printerShared.h"
#include "printerWeak.h"
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x

void OperatePrinter();
void OperatePrinterShared();
void OperatePrinterWeak();

int	main()
{
	OPERATION(OperatePrinter());
	OPERATION(OperatePrinterShared());
	OPERATION(OperatePrinterWeak());
}

//OperatePrinter. It creates a pointer to int and set an object with pointer value
//Constructor and destructor are called so no memory leak.
//In order to destructor to be called print object get out of scope(not known)
void OperatePrinter()
{
	Printer print;
	int num{};
	std::cout<<"Enter any number"<<std::endl;
	std::cin>>num;
	int *p = new int(num);
	print.setValue(p);

	if(*p>10)
	{
		delete p;
		p=nullptr;
	}

	print.print();
	delete p;
	p = nullptr;
}

//OperatePrinterShared. It creates a pointer to int and set an object with pointer value
//Constructor and destructor are called but shared counter is 1 not zero
//which means that the resource is not released
//In order to destructor to shared counter shall equal to zero
void OperatePrinterShared()
{
	PrinterShared print;
	int num{};
	std::cout<<"Enter any number"<<std::endl;
	std::cin>>num;
	std::shared_ptr<int> p{new int(num)};
	print.setValue(p);

	if(*p>10)
	{
		p=nullptr;
	}

	print.print();
}

//OperatePrinterWeak. It creates a pointer to int and set an object with pointer value
//Constructor and destructor are called but shared counter is zero
//Constructor and destructor are called so no memory leak.
void OperatePrinterWeak()
{
	PrinterWeak print;
	int num{};
	std::cout<<"Enter any number"<<std::endl;
	std::cin>>num;
	std::shared_ptr<int> p{new int(num)};
	print.setValue(p);

	if(*p>10)
	{
		p=nullptr;
	}

	print.print();
}