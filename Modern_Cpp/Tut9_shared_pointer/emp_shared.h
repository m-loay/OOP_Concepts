#pragma once
#include <iostream>
#include <memory>
#include "project.h"
class EmployeeShared
{
private:
	std::shared_ptr<Project> m_project;
public:
	EmployeeShared()
	{
		std::cout<<"EmployeeShared()"<<std::endl;
	}

	~EmployeeShared()
	{
		std::cout<<"~EmployeeShared()"<<std::endl;
	}

	void setProject(std::shared_ptr<Project> p)
	{
		std::cout<<"EmployeeShared::setProject(std::shared_ptr<Project>): "<<p.use_count() <<std::endl;
		m_project = p;
		std::cout<<"EmployeeShared::setProject(m_project = p): "<<p.use_count() <<std::endl;
	}

	std::shared_ptr<Project> getProject() const
	{
		return m_project;
	}
};