/*
 * Employee.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include "Employee.h"

#include <iostream>
using namespace std;

int Employee::count=0;

Employee::Employee(const string &first, const string &last)

{
	// TODO Auto-generated constructor stub
	firstName=first;
	lastName=last;
	++count;
	cout << "Employee object constructor: "
	<< firstName << ' '<< lastName << endl;
}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
	--count;
	cout << "Employee object destructor: "
	 << lastName << ", "<< firstName << endl;

}

string Employee::getFirstName()const
{
	return firstName;
}

string Employee::getFLastName()const
{
	return lastName;
}
int Employee::getCount()
{
	return count;
}
