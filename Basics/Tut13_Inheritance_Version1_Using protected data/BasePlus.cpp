/*
 * BasePlus.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#include "BasePlus.h"

BasePlus::BasePlus(const string &first, const string &last, const string &ssn, double salary ,double cr , double gs)
:CommissionEmployee(first, last, ssn, gs, cr)
{
	// TODO Auto-generated constructor stub
	setBaseSalaray(salary);
	cout<<"constructor Called"<<endl;
}

BasePlus::~BasePlus()
{
	// TODO Auto-generated destructor stub
	cout<<"Destructor Called"<<endl;
}

void BasePlus::setBaseSalaray(double salary )
{
	baseSalary=(salary<0.0)?0.0:salary;
}

double BasePlus::getBaseSalary()const
{

	return baseSalary;
}

double BasePlus::earnings()const
{

	return baseSalary + ( commsssionRate * grossSales );
}

void BasePlus:: print()const
{

	cout<<"Commision Employee: "<<firstName<<' '<<lastName
		<<"\nSocial Security Number:"<<SocialNumber
		<<"\nGross Sales: "<<grossSales
		<<"\nBase Salary: "<<baseSalary
		<<"\nComsssion Rate: "<<commsssionRate<<endl;

}


