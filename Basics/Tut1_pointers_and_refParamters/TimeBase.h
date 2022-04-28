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
	Time_Base(const int &ref = 0);
	~Time_Base();
	void setTime (int h, int m, int s);
	void setCounter (const int &ref);
	int &getCounter ();

	int &badSetHour(int hh);
	void printUniversal();
	void printStandard ();

private:
	int hr_{0};
	int min_{0};
	int sec_{0};
	int& counter_;
};

#endif /* TIMEBASE_H_ */
