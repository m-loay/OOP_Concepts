#pragma once
#include <iostream>
#include <memory>
class PrinterShared
{
private:
	std::shared_ptr<int> m_pValue{};

public:
	PrinterShared()
	{
		std::cout<<"PrinterShared()"<<std::endl;
	}
	~PrinterShared()	
	{
		std::cout<<"~PrinterShared()"<<std::endl;
		std::cout<<"Ref counter:"<<m_pValue.use_count()<<std::endl;
	}

	void setValue(std::shared_ptr<int> p)
	{
		m_pValue = p;
	}

	int getValue(std::shared_ptr<int> p)
	{
		return *p;
	}

	void print() const
	{
		std::cout<<"PrinterShared():print"<<std::endl;
		std::cout<<"Ref counter:"<<m_pValue.use_count()<<std::endl;
		std::cout<<"Value is: "<<*m_pValue<<std::endl;
	}
};
