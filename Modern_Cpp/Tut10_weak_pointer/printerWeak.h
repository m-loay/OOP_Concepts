#pragma once
#include <iostream>
#include <memory>
class PrinterWeak
{
private:
	std::weak_ptr<int> m_pValue{};

public:
	PrinterWeak()
	{
		std::cout<<"PrinterWeak()"<<std::endl;
	}
	~PrinterWeak()	
	{
		std::cout<<"~PrinterWeak()"<<std::endl;
		std::cout<<"Ref counter:"<<m_pValue.use_count()<<std::endl;
	}

	void setValue(std::weak_ptr<int> p)
	{
		m_pValue = p;
	}

	void print() const
	{
		std::cout<<"PrinterWeak():print"<<std::endl;
		if(m_pValue.expired())
		{
			std::cout<<"Resource is no longer avalible"<<std::endl;
		}
		auto sp = m_pValue.lock();
		std::cout<<"Ref counter:"<<sp.use_count()<<std::endl;
		std::cout<<"Value is: "<<*sp<<std::endl;
	}
};
