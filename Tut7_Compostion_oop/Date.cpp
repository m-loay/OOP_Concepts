/*
 * Date.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int mn, int dy, int yr)
{
	// TODO Auto-generated constructor stub
	month=(mn>0 && mn<=monthsPerYear)? mn:1;
	year=(yr>0 && yr<=2016)?yr:1995;
	day=(dy>0 && dy<=31)? dy:1;
	cout << "Date object constructor for date ";
	print();
}

void Date::print() const
{
	cout << month << '/'<< day << '/'<< year<<endl;
}
Date::~Date()
{
	// TODO Auto-generated destructor stub
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

