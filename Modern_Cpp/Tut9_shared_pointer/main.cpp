#include <iostream>
#include <memory>

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

class Employee
{
private:
	std::shared_ptr<Project> m_project;
public:
	Employee()
	{
		std::cout<<"Employee()"<<std::endl;
	}

	~Employee()
	{
		std::cout<<"~Employee()"<<std::endl;
	}

	void setProject(std::shared_ptr<Project> p)
	{
		std::cout<<"project count(setProject): "<<p.use_count()<<std::endl;
		m_project = p;
	}

	std::shared_ptr<Project> getProject()const
	{
		std::cout<<"project count(getProject): "<<m_project.use_count()<<std::endl;
		return m_project;
	}
};

std::shared_ptr<Employee> AssignProject()
{
	std::shared_ptr<Project> p {new Project{}};
	std::cout<<"project count(Main): "<<p.use_count()<<std::endl;

	std::shared_ptr<Employee> e1 {new Employee{}};
	e1->setProject(p);

	return std::shared_ptr<Employee>{e1};
}

int	main(int argc, char **argv)
{
	auto sp = AssignProject();
	return 0;
}