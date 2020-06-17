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
	Time_Base(int h, int m, int s,int t);
	~Time_Base();
	void setTime (int h, int m, int s,int t);
	int getHour (void);
	int &badSetHour(int hh);
	void printUniversal();
	void printStandard ();

private:
	int hour;
	int minute;
	int second;
	int timer;
};

#endif /* TIMEBASE_H_ */
