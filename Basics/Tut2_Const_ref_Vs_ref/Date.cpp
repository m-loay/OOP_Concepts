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
    month_ = (mn>0 && mn <= monthPerYear)?mn:1;
    year_ = (yr >1990 && yr<=2016)?yr:1990;
    day_ = (dy> 0 && dy<=30)?dy:1;
    ID_ =id;

    cout <<"constructor Date of id "<<ID_<<" has been called"<<endl;
}


Date::~Date()
{
    // TODO Auto-generated destructor stub
    cout <<"destructor Date of id "<<ID_<<" has been called"<<endl;
}

void Date::setDay(int dy)
{
    day_ = (dy> 0 && dy<=30)?dy:1;
}

int Date::getDay()const
{
    return day_;
}

void Date::print() const
{
    cout <<month_ <<"/"<<day_<<"/"<<year_<<endl;
}

