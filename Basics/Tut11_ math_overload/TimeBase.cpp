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
int Time_Base::count=0;

Time_Base::Time_Base(int h , int m, int s)
{
	// TODO Auto-generated constructor stub
	hour=h;
	minute=m;
	second=s;
	count++;
	cout<<"Constructor Called"<< count<<endl;
}

Time_Base::~Time_Base()
{
	// TODO Auto-generated destructor stub
	count--;
	cout<<"Destructor Called"<< count <<endl;
}

void Time_Base::setTime (int h, int m, int s)

{
	hour=(h>=0 && h<24)? h:0;
	minute= (m>=0 && m<60)? m:0;
	second= (s>=0 && s<60) ? s:0;
}

const Time_Base &Time_Base::operator ++()
{
	hour++;
	minute++;
	second++;
	return *this;
}

const Time_Base Time_Base::operator ++(int d)
{

	Time_Base temp = *this;
	hour++;
	minute++;
	second++;
	return temp;
}

const Time_Base &Time_Base::operator +(int d)
{
	hour+=d;
	minute+=d;
    second+=d;
	return *this;
}

const Time_Base &Time_Base::operator +(const Time_Base &a)
{
	this->hour+=a.hour;
	this->minute+=a.minute;
	this->second+=a.second;

	return *this;
}

ostream &operator<<(ostream &output , const Time_Base &a )
{
	output<<setfill('0')<<setw(2)<<a.hour<<":"<<
			setw(2)<<a.minute<<":"<<
			setw(2)<<a.second<<endl;

	return output;
}

void Time_Base:: printUniversal()
{
	cout<<setfill('0')<<setw(2)<<hour<<":"<<
			setw(2)<<minute<<":"<<
			setw(2)<<second<<endl;
}

void Time_Base:: printStandard ()
{
	cout << ((hour == 0|| hour== 12) ? 12: hour % 12) <<":"<<setfill('0')<<setw(2)<<minute<<":"<<
			setw(2)<<second<<(hour < 12? " AM": " PM")<<endl;
}
