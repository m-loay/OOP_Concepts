/*
 * HourlyEmployee.h
 *
 *  Created on: Jun 24, 2016
 *      Author: modys
 */

#ifndef HOURLYEMPLOYEE_H_
#define HOURLYEMPLOYEE_H_
#include <iostream>
#include <string>
#include "employee.h"
using namespace std;
class HourlyEmployee  :public employee
{
public:
	static const int hoursPerWeek= 168;
	HourlyEmployee(const string &, const string &, const string &, double=0, double=0);
	 ~HourlyEmployee();

		void setWages (double);
		double getWages() const;

		void setHours (double);
		double getHours() const;

		virtual double earnings()const override;
		virtual void print() const override;

private:
		double wages;
		double hours;
};

#endif /* HOURLYEMPLOYEE_H_ */
