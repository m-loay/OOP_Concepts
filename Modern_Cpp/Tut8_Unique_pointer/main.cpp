#include <iostream>
#include <memory>
#include"Integer.h"

void Display(Integer *p)
{
	if(!p)
	{
		return;
	}
	std::cout<< p->GetValue() << std::endl;
}

Integer * GetPointer(int value)
{
	Integer *p = new Integer{value};
	return p;
}

void operate(int value)
{
	//Integer *p = GetPointer(value);
	std::unique_ptr<Integer> p {GetPointer(value)};
	if(!p)
	{
		// p = new Integer{value};
		p.reset(new Integer{value});//create a new pointer
	}
	p->SetValue(100);
	Display(p.get());//pass the pointer itself
	// Display(p);

	// delete p;
	p = nullptr;

	// p = new Integer{};
	p.reset(new Integer{});
	*p = __LINE__;
	Display(p.get());
	// Display(p);
	// delete p;
}

int	main()
{
	operate(5);
	return 0;
}

