#include "Integer.h"
#include <iostream>
#include<memory>
class IntPtr
{
	public:
	IntPtr(Integer *p):m_p(p)
	{
		std::cout << "IntPtr()"<<std::endl;
	}
	~IntPtr()
	{
		std::cout << "~IntPtr()" <<" "<< m_p->GetValue() <<std::endl;
		delete m_p;
	}

	Integer *operator -> ()
	{
		return m_p;
	}

	private:
	Integer *m_p;
};

void process(std::unique_ptr<Integer> p_uni)
{
	std::cout<<"process unique_ptr smart Pointer = "<<p_uni->GetValue()<<std::endl;
}

void process(std::shared_ptr<Integer> p_shared)
{
	std::cout<<"process shared_ptr smart Pointer = "<<p_shared->GetValue()<<std::endl;
}

void creatIntger()
{
	//created smart pointer
	IntPtr p = new Integer;
	p->SetValue(3);
	std::cout<<"Created smart Pointer = "<<p->GetValue()<<std::endl;

	//created unique smart pointer
	std::unique_ptr<Integer> p_uni(new Integer);
	p_uni->SetValue(1);
	std::cout<<"unique_ptr smart Pointer = "<<p_uni->GetValue()<<std::endl;
	process(std::move(p_uni));//need to use move , because copy constructor is deleted in unique_ptr 

	//created shared smart pointer
	std::shared_ptr<Integer> p_shared(new Integer);
	p_shared->SetValue(2);
	std::cout<<"shared_ptr smart Pointer = "<<p_shared->GetValue()<<std::endl;
	process(p_shared);
	std::cout<<"After process shared_ptr smart Pointer = "<<p_shared->GetValue()<<std::endl;
}

int main() 
{
	creatIntger();
	
	return 0;
}