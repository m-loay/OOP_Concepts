/*
 * TimeBase.h
 *
 *  Created on: Jun 14, 2016
 *      Author: modys
 */

#ifndef TIMEBASE_H_
#define TIMEBASE_H_

#include "iostream"
using namespace std;

class Time_Base
{
public:
	Time_Base(int= 0, int= 0,int= 0);
	~Time_Base();

	Time_Base &setTime (int , int , int );
	Time_Base &setHour (int  );
	Time_Base &setMin (int );
	Time_Base &setSec (int );

	void printUniversal()const;
	void printStandard ()const;

private:
	int hour;
	int minute;
	int second;
};

#endif /* TIMEBASE_H_ */
