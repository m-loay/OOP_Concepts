/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include<iostream>
#include "Date.h"
using namespace std;

void printObj (const Date &x);

int main()
{
	Date d1(7,1,1990,1);
	Date d2 (10,1,2016,2);
	Date d3 (10,1,2016,3);

	cout<<"++d1 = "<<++d1<<endl;
	cout<<"After ++d1 = "<<d1<<endl;

	cout<<"d1++ = "<<d1++<<endl;
	cout<<"After d1++ = "<<d1<<endl;

	d2 = ++d1;
	cout<<"d2 = d1++ = "<<d2<<endl;

	d3 = d1++;
	cout<<"d3 = d1++ = "<<d3<<endl;

	printObj(d1);

}

void printObj (const Date &x)
{
	cout<<"day = "<<x.getDay()<<endl;
}
