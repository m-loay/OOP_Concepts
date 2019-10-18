/*
 * Date.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: modys
 */

#include <iostream>
#include <stdexcept>
#include "Date.h"
using namespace std;
Date::Date(int mn ,int dy, int yr,int id)
{
	// TODO Auto-generated constructor stub
	month = (mn>0 && mn <= monthPerYear)?mn:1;
	year = (yr >1990 && yr<=2016)?yr:1990;
	day = (dy> 0 && dy<=30)?dy:1;
	ID =id;

	cout <<"constructor Date of id "<<ID<<"has been called"<<endl;
}

Date::~Date()
{
	// TODO Auto-generated destructor stub
	cout <<"destructor Date of id "<<ID<<"has been called"<<endl;
}

void Date::print() const
{
	cout <<month <<"/"<<day<<"/"<<year<<endl;
}
