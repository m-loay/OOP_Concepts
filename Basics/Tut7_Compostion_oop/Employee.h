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

class EmployeeNoMemberInitializer
{
public:
	EmployeeNoMemberInitializer(const string & , const string & , const Date & , const Date &);
	virtual ~EmployeeNoMemberInitializer();
	void print () const;

private:
	string firstName;
	string lastName;
	Date birthDate;
	Date hireDate;
};

class EmployeeWithMemberInitializer
{
public:
	EmployeeWithMemberInitializer(const string & , const string & , const Date & , const Date &);
	virtual ~EmployeeWithMemberInitializer();
	void print () const;

private:
	string firstName;
	string lastName;
	Date birthDate;
	Date hireDate;
};

class EmployeeWithMemberInitializerREF
{
public:
	EmployeeWithMemberInitializerREF(const string & , const string & , const Date & , const Date &);
	virtual ~EmployeeWithMemberInitializerREF();
	void print () const;

private:
	string firstName;
	string lastName;
	const Date &birthDate;
	const Date &hireDate;
};

#endif /* EMPLOYEE_H_ */
