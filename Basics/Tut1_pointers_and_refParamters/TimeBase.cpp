/*
 * TimeBase.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: modys
 */

#include "TimeBase.h"
#include <iomanip>
#include <iostream>


Time_Base::Time_Base(const int &ref = 0):counter(const_cast<int &>(ref))
{
	std::cout<<"Time Base Constructor"<<std::endl;
	// TODO Auto-generated constructor stub
}

Time_Base::~Time_Base()
{
	std::cout<<"Time Base Destructor"<<std::endl;
	// TODO Auto-generated destructor stub
}

void Time_Base:: setTime (int h, int m, int s)

{
	hour=(h>=0 && h<24)? h:0;
	minute= (m>=0 && m<60)? m:0;
	second= (s>=0 && s<60) ? s:0;
}

void Time_Base:: setCounter (const int &ref)
{
	counter = const_cast<int &>(ref);
}

int &Time_Base::getCounter()
{
	return counter;
}

 int  &Time_Base:: badSetHour(int hh)
{
	hour = ( hh >= 0&& hh < 24) ? hh : 0;
	return hour; // DANGEROUS reference return
}

void Time_Base:: printUniversal()
{
	std::cout<<setfill('0')<<setw(2)<<hour<<":"<<
			setw(2)<<minute<<":"<<
			setw(2)<<second<<std::endl;
}
void Time_Base:: printStandard ()
{
	std::cout << ((hour == 0|| hour== 12) ? 12: hour % 12) <<":"<<setfill('0')<<setw(2)<<minute<<":"<<
			setw(2)<<second<<(hour < 12? " AM": " PM")<<std::endl;
}
