#pragma once
#include <iostream>
#include <memory>
#include "employeeShared.h"
class EmployeeShared;
class ProjectShared
{
private:
    std::shared_ptr<EmployeeShared> m_empShared;
public:
    ProjectShared()
	{
		std::cout<<"ProjectShared()"<<std::endl;
	}

	~ProjectShared()
	{
		std::cout<<"~ProjectShared()"<<std::endl;
	}
    void setEmployee(std::shared_ptr<EmployeeShared> p)
    {
        std::cout<<"====Start of ProjectShared::setEmployee()===="<<std::endl;

        std::cout<<"number of EmployeeShared pointer created Before Assignation: "<<p.use_count() <<std::endl;
        m_empShared = p;
        std::cout<<"number of EmployeeShared pointer created After Assignation: "<<p.use_count() <<std::endl;

        std::cout<<"====End of ProjectShared::setEmployee()===="<<std::endl;
    }
};
