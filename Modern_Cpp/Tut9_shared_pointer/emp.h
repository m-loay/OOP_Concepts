#pragma once
#include <iostream>
#include "project.h"
class Employee
{
private:
	Project *m_project;
public:
	Employee()
	{
		std::cout<<"Employee()"<<std::endl;
	}

	~Employee()
	{
		std::cout<<"~Employee()"<<std::endl;
	}

	void setProject(Project *p)
	{
		std::cout<<"Employee::setProject(Project *p): "<<std::endl;
		m_project = p;
	}

	Project * getProject() const
	{
		return m_project;
	}
};