/*
 * Employee.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include "Employee.h"
#include "Date.h"
#include <iostream>
using namespace std;

Employee::Employee(const string &first, const string &last,
		   const Date &dateOfBirth, const Date &dateOfHire)
: birthDate(dateOfBirth), hireDate(dateOfHire)
{
	// TODO Auto-generated constructor stub
	firstName=first;
	lastName=last;

	cout << "Employee object constructor: "
	<< firstName << ' '<< lastName << endl;
}

Employee::~Employee()
{
	cout << "Employee object Destructor: ";
}

void Employee::print()const
{
	cout << lastName <<", "<< firstName << " Hired: ";
	hireDate.print();
	cout << " Birthday: ";
	birthDate.print();
	cout<<endl;
}



