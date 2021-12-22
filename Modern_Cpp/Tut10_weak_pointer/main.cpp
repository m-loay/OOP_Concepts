#include <iostream>
#include <memory>
#include"employeeShared.h"
#include"ProjectShared.h"
#include "employeeWeak.h"
#include "ProjectWeak.h"
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x


std::pair<std::shared_ptr<ProjectShared>, std::shared_ptr<EmployeeShared>> OperateShared();
std::pair<std::weak_ptr<ProjectWeak>, std::weak_ptr<EmployeeWeak>> OperateWeak();

int	main()
{
	//A circular created dependency, the destructor of both projectShared, EmployeeShared
    // will not be called since shared pointer were not destroyed.
    OPERATION(auto p = OperateShared());
	std::cout<<"number of projectShared pointer created: "<<p.first.use_count() <<std::endl;
	std::cout<<"number of EmployeeShared pointer created: "<<p.second.use_count() <<std::endl;

    //A circular created dependency, the destructor of both projectWeak, ProjectWeak
    // will not be called since shared pointer were not destroyed.
	OPERATION(auto w = OperateWeak());
    if(w.first.expired())
    {
        std::cout<<"number of projectWeak pointer created is none"<<std::endl;
    }
    else
    {
        std::cout<<"number of projectWeak pointer created: "<<w.first.use_count() <<std::endl;
    }
    if(w.second.expired())
    {
        std::cout<<"number of EmployeeShared pointer created is none"<<std::endl;
    }
    else
    {
        std::cout<<"number of EmployeeShared pointer created: "<<w.second.use_count() <<std::endl;
    }

}

std::pair<std::shared_ptr<ProjectShared>, std::shared_ptr<EmployeeShared>> OperateShared()
{
    std::cout<<"====Start OperateShared===="<<std::endl;
	std::shared_ptr<ProjectShared> p {new ProjectShared{}};
	std::cout<<"number of projectShared pointer created: "<<p.use_count() <<std::endl;
	std::shared_ptr<EmployeeShared> e {new EmployeeShared{}};
	std::cout<<"number of EmployeeShared pointer created: "<<e.use_count() <<std::endl;

    std::cout<<"set employee to project: "<<p.use_count() <<std::endl;
	p->setEmployee(e);
    std::cout<<"number of EmployeeShared pointer created after setting: "<<e.use_count() <<std::endl;

    std::cout<<"set project to employee: "<<p.use_count() <<std::endl;
    e->setProject(p);
    std::cout<<"number of projectShared pointer created after setting: "<<p.use_count() <<std::endl;
    std::cout<<"====end OperateShared===="<<std::endl;
	return std::make_pair(p,e);
}

std::pair<std::weak_ptr<ProjectWeak>, std::weak_ptr<EmployeeWeak>> OperateWeak()
{
    std::cout<<"====Start OperateShared===="<<std::endl;
    std::shared_ptr<ProjectWeak> p {new ProjectWeak{}};
    std::weak_ptr<ProjectWeak>pw(p);
    std::cout<<"number of ProjectWeak Shared pointer created: "<<p.use_count() <<std::endl;
    std::cout<<"number of ProjectWeak Weak pointer created: "<<pw.use_count() <<std::endl;

    std::shared_ptr<EmployeeWeak> e {new EmployeeWeak{}};
    std::weak_ptr<EmployeeWeak>ew(e);
    std::cout<<"number of EmployeeWeak shared pointer created: "<<e.use_count() <<std::endl;
    std::cout<<"number of EmployeeWeak Weak pointer created: "<<pw.use_count() <<std::endl;

    std::cout<<"set employee to project: "<<p.use_count() <<std::endl;
    p->setEmployee(ew);
    std::cout<<"number of EmployeeWeak shared pointer created after setting: "<<e.use_count() <<std::endl;
    std::cout<<"number of EmployeeWeak Weak pointer created after setting: "<<ew.use_count() <<std::endl;

    std::cout<<"set project to employee: "<<p.use_count() <<std::endl;
    e->setProject(pw);
    std::cout<<"number of ProjectWeak shared pointer created after setting: "<<p.use_count() <<std::endl;
    std::cout<<"number of ProjectWeak Weak pointer created after setting: "<<pw.use_count() <<std::endl;
    return std::make_pair(pw,ew);
}