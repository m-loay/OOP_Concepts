/*
 * CommissionEmployee.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, double gs,double cr)
:employee(first, last, ssn)
{
	// TODO Auto-generated constructor stub
	setComissionRate(cr);
	setGrossSales(gs);

	cout<<"  CommissionEmployee Constructor  Called"<<endl;
}

CommissionEmployee::~CommissionEmployee()
{
	// TODO Auto-generated destructor stub
	cout<<" CommissionEmployee Destructor  Called"<<endl;
}

void CommissionEmployee::setGrossSales(double gs)
{
	grossSales=(gs<0.0)?0.0:gs;
}

double CommissionEmployee::getGrossSales()const
{
	return grossSales;
}


void CommissionEmployee::setComissionRate(double cr)
{
	commsssionRate=(cr<0.0)?0.0:cr;
}

double CommissionEmployee::getComissionRate()const
{
	return commsssionRate;
}


double CommissionEmployee::earnings()const
{
	return getComissionRate() * getGrossSales();
}

void CommissionEmployee::print()const
{
	cout<<"CommissionEmployee Sales: "<<endl;
	employee::print();
	cout<<"\nGross Sales: "<<getGrossSales()
		<<"\nComsssion Rate: "<<getComissionRate()<<endl;
}
