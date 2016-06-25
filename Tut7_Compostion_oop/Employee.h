/*
 * Employee.h
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "Date.h"
#include<string>
using namespace std;

class Employee {
public:
	Employee(const string &, const string &,
			   const Date &, const Date &);
	void print() const;
	~Employee();

private:
	string firstName;
	string lastName;
	const Date birthDate;
	const Date hireDate;
};

#endif /* EMPLOYEE_H_ */
