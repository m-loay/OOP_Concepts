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

int Date::getDay()const
{
	return day;
}

// overloaded prefix increment operator
const Date &Date::operator++()
{
	++day;
	return *this; // reference return to create an l-value
} // end function operator+

const Date &Date::operator++( int )
{
	static Date &temp =*this; // hold current state of object
	day++;
	// return unincremented,saved, temporary object
	return temp; // value return; nota reference return
} // end function operator++

const  Date &Date:: operator =(const Date &right)
{
	if( &right != this)
	{
		day = right.day;
		month = right.month;
		year = right.year;
		// for Arrays of different sizes, deallocate original
		// left-side array, then allocate new left-side array

	} // end outer if

	return *this; // enables x = y = z, for example
}// end function operator=

void Date::print() const
{
	cout <<month <<"/"<<day<<"/"<<year<<endl;
}


ostream &operator<<( ostream &output, const Date &d )
{

	output<<d.day<< ", " << d.year;
	return output; // enables cascading
} // end function operator<<
