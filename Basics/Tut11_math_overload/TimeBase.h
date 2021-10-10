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
	friend ostream &operator<<( ostream &, const Time_Base & );
	friend istream &operator>>( istream &, Time_Base & );
public:
	Time_Base(int=0 , int=0 , int=0);
	Time_Base(const Time_Base&);
	~Time_Base();
	void setTime (int h, int m, int s);
	const Time_Base &operator++();
	const Time_Base operator++(int d);
	const Time_Base &operator+(int d);
	const Time_Base &operator+(const Time_Base & );
	void printUniversal();
	void printStandard ();

private:
	int hour;
	int minute;
	int second;
	static int count;
	int id;
};

#endif /* TIMEBASE_H_ */
