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
	Time_Base(const int &ref);
	~Time_Base();
	void setTime (int h, int m, int s);
	void setCounter (const int &ref);
	int &getCounter ();

	 int &badSetHour(int hh);
	void printUniversal();
	void printStandard ();

private:
	int hour;
	int minute;
	int second;
	int & counter;
};

#endif /* TIMEBASE_H_ */
