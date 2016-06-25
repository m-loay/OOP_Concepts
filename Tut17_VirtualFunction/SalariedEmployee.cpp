/*
 * SalariedEmployee.cpp
 *
 *  Created on: Jun 24, 2016
 *      Author: modys
 */

#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee(const string &first, const string &last, const string &ssn, double salary)
:employee(first, last, ssn)
{
	// TODO Auto-generated constructor stub
	setWeeklySalary(salary);
	cout<<"  SalariedEmployee Constructor  Called"<<endl;

}

SalariedEmployee::~SalariedEmployee()
{
	// TODO Auto-generated destructor stub
	cout<<"SalariedEmployee Destructor  Called"<<endl;
}

void SalariedEmployee::setWeeklySalary(double salary)
{
	weeklySalary = ( salary < 0.0) ? 0.0: salary;
}

double SalariedEmployee::getWeeklySalary()const
{
	return weeklySalary;
}

double SalariedEmployee::earnings()const
{
	return getWeeklySalary();
}

void SalariedEmployee::print()const
{
	cout<<"SalariedEmployee"<<endl;
	employee::print();
	cout<<"Weekly salaries: "<<getWeeklySalary();
}
