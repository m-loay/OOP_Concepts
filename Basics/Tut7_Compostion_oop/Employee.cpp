/*
 * Employee.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: modys
 */

#include "Employee.h"
#include <iostream>
using namespace std;
Employee::Employee(const string &first , const string &last , const Date &db , const Date &hb)
:firstName(first),
 lastName(last),
 birthDate(db),
hireDate(hb)
{
	// TODO Auto-generated constructor stub
	cout<<"Employee OBJ constructor "<<firstName<<" "<<lastName<<"called"<<endl;
}

Employee::~Employee()
{
	// TODO Auto-generated destructor stub
	cout<<"Employee OBJ destructor "<<firstName<<" "<<lastName<<"called"<<endl;
}

void Employee::print()const
{
	cout<<"Employee "<<firstName<<" "<<lastName<<" was born in"<<endl;
	birthDate.print();
	cout <<"and hired in ";
	hireDate.print();
}

