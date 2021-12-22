#pragma once
#include <iostream>
#include <memory>
#include "ProjectWeak.h"
class ProjectWeak;
class EmployeeWeak
{
private:
    std::weak_ptr<ProjectWeak> m_projWeak;
public:
    EmployeeWeak()
    {
        std::cout<<"EmployeeWeak()"<<std::endl;
    }

    ~EmployeeWeak()
    {
        std::cout<<"~EmployeeWeak()"<<std::endl;
    }
    void setProject(std::weak_ptr<ProjectWeak> p)
    {
        std::cout<<"====Start of EmployeeWeak::setProject()===="<<std::endl;

        std::cout<<"number of ProjectWeak pointer created before assignation: "<<p.use_count() <<std::endl;
        m_projWeak = p;
        std::cout<<"number of ProjectWeak pointer created after assignation: "<<p.use_count() <<std::endl;

        std::cout<<"====End of EmployeeWeak::setProject()===="<<std::endl;
    }
};