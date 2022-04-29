/*
 * CommissionEmployee.h
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#ifndef COMMISSIONEMPLOYEE_H_
#define COMMISSIONEMPLOYEE_H_

#include <iostream>
#include <string>
using namespace std;

class CommissionEmployee
{
public:
	CommissionEmployee(const string &, const string &, const string &,
			           double=0,double=0);
	~CommissionEmployee();

	void setFirstName (const string &);
	string getFirstName() const;

	void setLastName (const string &);
	string getLastName() const;

	void setSocialNumber (const string &);
	string getSocialNumber() const;

	void setGrossSales (double);
	double getGrossSales() const;

	void setComissionRate (double);
	double getComissionRate() const;

	double earnings()const;
	void print() const;

protected:
	string firstName;
	string lastName;
	string SocialNumber;
	double grossSales;
	double commsssionRate;

};

#endif /* COMMISSIONEMPLOYEE_H_ */
