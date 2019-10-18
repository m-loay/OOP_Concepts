/*
 * TimeBase.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: modys
 */

#include "TimeBase.h"
#include <iomanip>
#include <iostream>

using namespace std;

Time_Base::Time_Base(int hr, int min,int sec)
{
	// TODO Auto-generated constructor stub
	setTime(hr, min , sec);
}

Time_Base::~Time_Base()
{
	// TODO Auto-generated destructor stub
}

Time_Base &Time_Base:: setTime (int h, int m, int s)

{
	setHour(h);
	setMin(m);
	setSec(s);
	return *this;
}

 Time_Base &Time_Base:: setHour (int h)

{
	hour=(h>=0 && h<24)? h:0;
	return *this;
}

 Time_Base &Time_Base:: setMin (int m)

{
	minute= (m>=0 && m<60)? m:0;
	return *this;
}

 Time_Base &Time_Base:: setSec (int s)

{
	second= (s>=0 && s<60) ? s:0;
	return *this;
}


void Time_Base:: printUniversal() const
{
	cout<<setfill('0')<<setw(2)<<hour<<":"<<
			setw(2)<<minute<<":"<<
			setw(2)<<second<<endl;
}
void Time_Base:: printStandard () const
{
	cout << ((hour == 0|| hour== 12) ? 12: hour % 12) <<":"<<setfill('0')<<setw(2)<<minute<<":"<<
			setw(2)<<second<<(hour < 12? " AM": " PM")<<endl;
}
