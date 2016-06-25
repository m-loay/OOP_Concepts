/*
 * Date.h
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#ifndef DATE_H_
#define DATE_H_


class Date {
public:
	static const int monthsPerYear=12;
	Date(int=1, int=1, int=1900);
	void print()const;
	~Date();

private:
	int month,day,year;
};

#endif /* DATE_H_ */
