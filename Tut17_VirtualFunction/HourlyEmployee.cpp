/*
 * HourlyEmployee.cpp
 *
 *  Created on: Jun 24, 2016
 *      Author: modys
 */

#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(const string &first, const string &last, const string &ssn, double wag, double hr)
:employee(first, last, ssn)
{
	// TODO Auto-generated constructor stub
	setWages(wag);
	setHours(hr);
	cout<<"  HourlyEmployee Constructor  Called"<<endl;

}

HourlyEmployee::~HourlyEmployee() {
	// TODO Auto-generated destructor stub
	cout<<"HourlyEmployee Destructor  Called"<<endl;
}

void HourlyEmployee::setWages(double wag)
{
	wages = ( wag < 0.0 ? 0.0 : wag );
}

double HourlyEmployee::getWages()const
{
	return wages;
}

void HourlyEmployee::setHours(double hr)
{
	hours = ( ( ( hr >= 0.0) &&
			( hr <= hoursPerWeek) ) ? hr : 0.0);
}

double HourlyEmployee::getHours()const
{
	return hours;
}

double HourlyEmployee::earnings()const
{

	if( getHours() <= 40) // no overtime
		return getWages() * getHours();
	else
		return 40* getWages() + ( ( getHours() - 40) * getWages() * 1.5);

}

void HourlyEmployee::print()const
{
	cout<<"Hourly Employee"<<endl;
	employee::print();
	cout<<"Hourly wage: "<<getWages()
	    		<<"\n Hours Worked: "<<getHours();
}
