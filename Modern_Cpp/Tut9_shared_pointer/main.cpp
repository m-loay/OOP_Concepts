#include <iostream>
#include "project.h"
#include "emp.h"
#include "emp_shared.h"
#include <memory>
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x


Employee * AssignProjectNormalPointers();
std::shared_ptr<EmployeeShared> AssignProjectSmartPointers();

int	main(int argc, char **argv)
{
	// This will create constructor for both employee and Project class
	//It wont call destructor class which a prove of memory leack
	OPERATION(auto sp = AssignProjectNormalPointers());

	//Using smart pointers constructor & destructor will be called for both classes
	OPERATION(auto spShared = AssignProjectSmartPointers());
	return 0;
}

//AssignProjectNormalPointers project on employee
Employee * AssignProjectNormalPointers()
{
	Project * p {new Project{}};
	Employee * e1 {new Employee{}};
	e1->setProject(p);

	return e1;
}

//AssignProjectSmartPointers project on employee
//When created std::shared_ptr<Project> p ,shared pointer counter increments to become 1
//when std::shared_ptr<Project> p passed by value to setProject(), shared pointer counter increments to become 2
//when std::shared_ptr<Project> p assigned to m_project, shared pointer counter increments to become 3
//when setProject() executed, shared pointer counter decrements to become 2
//when AssignProjectSmartPointers() executed
// --> shared pointer counter decrements to become 1 because std::shared_ptr<Project> p is destroyed
// --> shared pointer counter decrements to become 0 because object e is destroyed

std::shared_ptr<EmployeeShared> AssignProjectSmartPointers()
{
	std::shared_ptr<Project> p {new Project{}};
	std::cout<<"AssignProjectSmartPointers: "<<p.use_count() <<std::endl;
	std::shared_ptr<EmployeeShared> e1 {new EmployeeShared{}};
	e1->setProject(p);
	std::cout<<"AssignProjectSmartPointers --> serProject(): "<<p.use_count() <<std::endl;

	return e1;
}