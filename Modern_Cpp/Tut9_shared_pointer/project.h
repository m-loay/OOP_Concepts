#pragma once
#include <iostream>
class Project
{
public:
	Project()
	{
		std::cout<<"Project()"<<std::endl;
	}

	~Project()
	{
		std::cout<<"~Project()"<<std::endl;
	}
};
