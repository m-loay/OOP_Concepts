/*
 * Employee.h
 *
 *  Created on: Sep 22, 2016
 *      Author: modys
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
#include "Date.h"

using namespace std;

class Employee
{
public:
	Employee(const string & , const string & , const Date & , const Date &);
	virtual ~Employee();
	void print () const;

private:
	string firstName;
	string lastName;
	const Date birthDate;
	const Date hireDate;
};

#endif /* EMPLOYEE_H_ */
