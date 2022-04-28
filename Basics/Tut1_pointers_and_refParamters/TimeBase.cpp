/*
 * TimeBase.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: modys
 */

#include "TimeBase.h"
#include <iomanip>
#include <iostream>


Time_Base::Time_Base(const int &ref):counter_(const_cast<int &>(ref))
{
	std::cout<<"Time Base Constructor"<<std::endl;
}

Time_Base::~Time_Base()
{
	std::cout<<"Time Base Destructor"<<std::endl;

}

void Time_Base::setTime(int h, int m, int s)
{
	hr_  = (h>= 0 && h <24)?h:0;
	min_ = (m>= 0 && m <60)?m:0;
	sec_ = (s>= 0 && s <24)?s:0;
}

void Time_Base::setCounter(const int &ref)
{
	counter_ = const_cast<int&>(ref);
}

int& Time_Base::getCounter()
{
	return counter_;
}

int& Time_Base::badSetHour(int hh)
{
	hr_  = (hh>= 0 && hh <24)?hh:0;
	return hr_; // DANGEROUS reference return
}

void Time_Base::printUniversal()
{
	std::cout<<setfill('0')<<setw(2)<<hr_<<":"<<
			setw(2)<<min_<<":"<<
			setw(2)<<sec_<<std::endl;

}


void Time_Base::printStandard()
{
	std::cout << ((hr_ == 0|| hr_== 12) ? 12: hr_ % 12) <<":"<<setfill('0')
							<<setw(2)<<min_<<":"<<setw(2)<<sec_
							<<(hr_ < 12? " AM": " PM")<<std::endl;

}
