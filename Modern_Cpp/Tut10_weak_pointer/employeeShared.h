#pragma once
#include <iostream>
#include <memory>
#include "ProjectShared.h"
class ProjectShared;
class EmployeeShared
{
private:
    std::shared_ptr<ProjectShared> m_projShared;
public:
    EmployeeShared()
    {
        std::cout<<"EmployeeShared()"<<std::endl;
    }

    ~EmployeeShared()
    {
        std::cout<<"~EmployeeShared()"<<std::endl;
    }
    void setProject(std::shared_ptr<ProjectShared> p)
    {
        std::cout<<"====Start of EmployeeShared::setProject()===="<<std::endl;

        std::cout<<"number of ProjectShared pointer created before assignation: "<<p.use_count() <<std::endl;
        m_projShared = p;
        std::cout<<"number of ProjectShared pointer created after assignation: "<<p.use_count() <<std::endl;

        std::cout<<"====End of EmployeeShared::setProject()===="<<std::endl;
    }
};