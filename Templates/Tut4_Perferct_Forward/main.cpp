#include <iostream>
#include "Integer.h"
#include <string>

/*******************************************************************************
 *  Class Employee                                                      *
 *******************************************************************************/
class Employee 
{
	std::string m_Name;
	Integer m_Id;
public:

	Employee(const std::string &name, const Integer &id) :m_Name{ name },m_Id{ id } 
	{
		std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	}

	Employee(std::string &&name, Integer &&id) :m_Name{ name },m_Id{ id } 
	{
		std::cout << "Employee(std::string &&name, Integer &&id)" << std::endl; 
	}

	~Employee()
	{
		std::cout << "~Employee Num -->"<<m_Id.GetValue() << std::endl;
	}
};

/*******************************************************************************
 *  Class Employee Template                                                    *
 *******************************************************************************/
class EmployeeT 
{
	std::string m_Name;
	Integer m_Id;
public:
	template<typename T1, typename T2>
	EmployeeT(T1 &&name,  T2 &&id) :
	m_Name{ std::forward<T1>(name) },
	m_Id{ std::forward<T2>(id) }
	{
		std::cout << "EmployeeT(std::string &&name,  Integer &&id)/ Num -->"<<m_Id.GetValue() << std::endl;
	}

	~EmployeeT()
	{
		std::cout << "~EmployeeT(std::string &&name,  Integer &&id)/ Num -->"<<m_Id.GetValue() << std::endl;
	}
};

template<typename T1, typename T2>
EmployeeT *CreateT(T1 && a, T2 &&b) 
{
	return new EmployeeT(std::forward<T1>(a), std::forward<T2>(b));
}

/*******************************************************************************
 *  Main                                                        *
 *******************************************************************************/
int main() 
{
	Employee emp1{ "Loay", Integer{1}};

	std::string name = "Mohamed";
	Employee emp2{ name, 2 };

	return 0;
}