#include <iostream>

enum class Color{RED =0, GREEN, BLUE};

void FillColor(Color c)
{
	//fill background with some colors
	switch (c)
	{
	case Color::RED:
		std::cout<<"RED"<<std::endl;
		break;
	case Color::GREEN:
		std::cout<<"GREEN"<<std::endl;
		break;
	case Color::BLUE:
		std::cout<<"BLUE"<<std::endl;
		break;
	
	default:
		break;
	}
}
int main() 
{
	Color c = Color::RED;
	FillColor(c);
	FillColor(Color::GREEN);
	FillColor(static_cast<Color>(2));

	return 0;
}

