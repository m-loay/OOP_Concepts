/*
 * Date.h
 *
 *  Created on: Sep 22, 2016
 *      Author: modys
 */

#ifndef DATE_H_
#define DATE_H_
#include <iostream>
using namespace std;

class Date
{
	friend ostream &operator<<( ostream &, const Date &);
public:
	static const int monthPerYear = 12;
	Date(int =1, int = 1, int = 1900 ,int =1);
	virtual ~Date();
	int getDay()const;
	const Date &operator++(); // prefix increment operator
	const Date &operator++( int ); // postfix increment operator
	const Date &operator=(const Date&);
	void print () const;

private:
	int month;
	int year;
	int day;
	int ID;
};

#endif /* DATE_H_ */
