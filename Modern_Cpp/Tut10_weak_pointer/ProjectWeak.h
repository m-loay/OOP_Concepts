#pragma once
#include <iostream>
#include <memory>
#include "employeeWeak.h"
class EmployeeWeak;
class ProjectWeak
{
private:
    std::weak_ptr<EmployeeWeak> m_empWeak;
public:
    ProjectWeak()
	{
		std::cout<<"ProjectWeak()"<<std::endl;
	}

	~ProjectWeak()
	{
		std::cout<<"~ProjectWeak()"<<std::endl;
	}
    void setEmployee(std::weak_ptr<EmployeeWeak> p)
    {
        std::cout<<"====Start of ProjectWeak::setEmployee()===="<<std::endl;

        std::cout<<"number of EmployeeWeak pointer created Before Assignation: "<<p.use_count() <<std::endl;
        m_empWeak = p;
        std::cout<<"number of EmployeeWeak pointer created After Assignation: "<<p.use_count() <<std::endl;

        std::cout<<"====End of ProjectWeak::setEmployee()===="<<std::endl;
    }
};
