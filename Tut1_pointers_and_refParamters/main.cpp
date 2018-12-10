/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>
#include "TimeBase.h"
//using namespace std;
/*
 * call by value
 * call by pointer
 * call by ref
 * dangof returning a reference*/
int main()
{
	/*Creating object from time base*/
	Time_Base t;

	/*Creating pointer and ref to the time base object*/
	Time_Base *t_ptr=&t;
	Time_Base &t_ref=t;

	/*printing time using the object and use sitters*/
	cout<<"The init universal Time is";
	t.printUniversal();

	cout<<"The init standard time is";
	t.printStandard();

	t_ptr->setTime(13,27,6);
	cout<<"The init universal Time is";
	t_ptr->printUniversal();

	cout<<"The init standard time is";
	t_ptr->printStandard();

	t_ref.setTime(99,99,99);
	cout<<"The init universal Time is";
	t_ref.printUniversal();

	cout<<"The init standard time is";
	t_ref.printStandard();

	/*Using bad setting through function that return ref*/
	cout<<"Using bad setting through function that return ref"<<endl;

	int &h_ref=t.badSetHour(10);
	cout<<"The init universal Time is";
	t.printUniversal();

	cout<<"The init standard time is";
	t.printStandard();

	/*change time using the reference [not using sitters]*/
	h_ref=35;
	cout<<"h_ref= 35"<<endl;
	cout<<"The init universal Time is";
	t.printUniversal();

	cout<<"The init standard time is";
	t.printStandard();

	h_ref=3;
	cout<<"h_ref=15"<<endl;
	cout<<"The init universal Time is";
	t.printUniversal();

	cout<<"The init standard time is";
	t.printStandard();

}
