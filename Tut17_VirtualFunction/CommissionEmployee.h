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
#include "employee.h"
using namespace std;

class CommissionEmployee : public employee
{
public:
	CommissionEmployee(const string &, const string &, const string &, double=0,double=0);
	~CommissionEmployee();



	void setGrossSales (double);
	double getGrossSales() const;

	void setComissionRate (double);
	double getComissionRate() const;

	virtual double earnings()const;
	virtual void print() const;

private:

	double grossSales;
	double commsssionRate;

};

#endif /* COMMISSIONEMPLOYEE_H_ */
