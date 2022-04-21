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

Time_Base::Time_Base(int h, int m, int s,int t)
{
    // TODO Auto-generated constructor stub
    setTime(h, m, s, t);
    cout << ( timer == 1|| timer == 6? "\n": "");
    cout << "Object "<< timer << " constructor runs " << endl;
}

Time_Base::~Time_Base()
{
    // TODO Auto-generated destructor stub
    cout << ( timer == 1|| timer == 6? "\n": "");
    cout << "Object "<< timer << " destructor runs " << endl;
}

void Time_Base:: setTime (int h, int m, int s,int t)

{
    hour=(h>=0 && h<24)? h:0;
    minute= (m>=0 && m<60)? m:0;
    second= (s>=0 && s<60) ? s:0;
    timer=(t>=0 && t<7)?t:7;
}

int  &Time_Base:: badSetHour(int hh)
{
    hour = ( hh >= 0&& hh < 24) ? hh : 0;
    return hour; // DANGEROUS reference return
}

int Time_Base:: getHour (void)
{
    return hour;
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
