#include <iostream>
#include <memory>

class Printer
{
private:
	std::weak_ptr<int> m_pValue{};

public:
	Printer()
	{
		std::cout<<"Printer()"<<std::endl;
	}
	~Printer()	
	{
		std::cout<<"~Printer()"<<std::endl;
	}

	void setValue(std::weak_ptr<int> p)
	{
		m_pValue = p;
	}

	void print() const
	{
		if(m_pValue.expired())
		{
			std::cout<<"Resource is no longer avalible"<<std::endl;
		}
		auto sp = m_pValue.lock();
		std::cout<<"Ref counter:"<<sp.use_count()<<std::endl;
		std::cout<<"Value is: "<<*sp<<std::endl;
	}
};

int	main()
{
	Printer prnt;
	int num{};
	std::cin>>num;
	std::shared_ptr<int> p{new int{num}};
	prnt.setValue(p);
	prnt.print();

	if(*p>10)
	{
		p = nullptr;
	}
	prnt.print();
	return 0;
}