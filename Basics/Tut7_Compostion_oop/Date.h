/*
 * Date.h
 *
 *  Created on: Sep 22, 2016
 *      Author: modys
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	static const int monthPerYear = 12;
	Date(int =1, int = 1, int = 1900 ,int =1);
	virtual ~Date();
	void print () const;

private:
	int month;
	int year;
	int day;
	int ID;
};

#endif /* DATE_H_ */
