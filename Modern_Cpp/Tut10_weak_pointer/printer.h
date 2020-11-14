#pragma once
#include <iostream>
class Printer
{
private:
	int * m_pValue{};

public:
	Printer()
	{
		std::cout<<"Printer()"<<std::endl;
	}
	~Printer()	
	{
		std::cout<<"~Printer()"<<std::endl;
	}

	void setValue(int * p)
	{
		m_pValue = p;
	}

	void print() const
	{
		std::cout<<"Printer():print"<<std::endl;
		if(m_pValue == nullptr)
		{
			std::cout<<"Resource is not avalibale"<<std::endl;
		}
		else
		{
			std::cout<<"Value is: "<<*m_pValue<<std::endl;
		}
	}
};