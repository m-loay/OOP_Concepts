/*
 * BasePlus.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#include "BasePlus.h"

BasePlus::BasePlus(const string &first, const string &last, const string &ssn,
		           double salary ,double cr , double gs)
:CommissionEmployee(first, last, ssn, gs, cr)
{
	// TODO Auto-generated constructor stub
	setBaseSalaray(salary);
	cout<<"BasePlus constructor Called"<<endl;
}

BasePlus::~BasePlus()
{
	// TODO Auto-generated destructor stub
	cout<<"BasePlus Destructor Called"<<endl;
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

	return baseSalary + ( CommissionEmployee::commsssionRate * grossSales );
}

void BasePlus:: print()const
{
	//Note: protected data members of base class CommissionEmployee can be
	// used directly or through class name and scope operator
	// e.g: firstName or  CommissionEmployee::firstName

	cout<<"BasePlus Employee: "<<CommissionEmployee::firstName<<' '<<CommissionEmployee::lastName
		<<"\nSocial Security Number:"<<CommissionEmployee::SocialNumber
		<<"\nGross Sales: "<<grossSales
		<<"\nBase Salary: "<<baseSalary
		<<"\nComsssion Rate: "<<CommissionEmployee::commsssionRate<<endl;
}


