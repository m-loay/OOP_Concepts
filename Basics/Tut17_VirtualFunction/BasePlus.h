/*
 * BasePlus.h
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#ifndef BASEPLUS_H_
#define BASEPLUS_H_
#include <iostream>
#include "CommissionEmployee.h"

class BasePlus : public CommissionEmployee
{
public:
	BasePlus(const string &, const string &, const string &, double=0,double=0, double=0);
	~BasePlus();

	void setBaseSalaray(double);
	double getBaseSalary()const;

	virtual double earnings()const;
	virtual void print()const;

private:
	double baseSalary;
};

#endif /* BASEPLUS_H_ */
