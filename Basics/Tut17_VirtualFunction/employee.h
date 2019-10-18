/*
 * employee.h
 *
 *  Created on: Jun 24, 2016
 *      Author: modys
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <string>
using namespace std;
class employee {
public:
	employee(const string &, const string &, const string &);
	virtual ~employee();

	void setFirstName (const string &);
	string getFirstName() const;

	void setLastName (const string &);
	string getLastName() const;

	void setSocialNumber (const string &);
	string getSocialNumber() const;

	virtual double earnings()const=0;
	virtual void print() const;

private:
	string firstName;
	string lastName;
	string SocialNumber;
};

#endif /* EMPLOYEE_H_ */
