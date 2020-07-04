/*
 * SalariedEmployee.h
 *
 *  Created on: Jun 24, 2016
 *      Author: modys
 */

#ifndef SALARIEDEMPLOYEE_H_
#define SALARIEDEMPLOYEE_H_
#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

class SalariedEmployee  : public employee
{
public:
	SalariedEmployee(const string &, const string &, const string &, double=0);
	~SalariedEmployee();

	void setWeeklySalary (double);
	double getWeeklySalary()const;

	virtual double earnings()const override;
	virtual void print() const override;

private:
	double weeklySalary;

};

#endif /* SALARIEDEMPLOYEE_H_ */
