/*
 * CommissionEmployee.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, double gs,double cr)
:firstName(first),lastName(last),SocialNumber(ssn)
{
	// TODO Auto-generated constructor stub
	commsssionRate=cr;
	grossSales=gs;
	cout<<"Constructor base  Call"<<endl;
}

CommissionEmployee::~CommissionEmployee()
{
	// TODO Auto-generated destructor stub
	cout<<"Destructor base Call"<<endl;
}

void CommissionEmployee::setFirstName(const string &first)
{
	firstName=first;
}

string CommissionEmployee::getFirstName() const
{
	return firstName;
}


void CommissionEmployee::setLastName(const string & last)
{
	lastName=last;
}

string CommissionEmployee::getLastName() const
{
	return lastName;
}


void CommissionEmployee::setSocialNumber(const string & ssn)
{
	SocialNumber=ssn;
}

string CommissionEmployee::getSocialNumber() const
{
	return SocialNumber;
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
	cout<<"Commision Employee: "<<getFirstName()<<' '<<getLastName()
		<<"\nSocial Security Number:"<<getSocialNumber()
		<<"\nGross Sales: "<<getGrossSales()
		<<"\nEarning: "<<earnings()<<endl;
}
