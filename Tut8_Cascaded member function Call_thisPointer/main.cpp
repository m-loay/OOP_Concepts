/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include <iostream>
#include "TimeBase.h"

using namespace std;

int main ()
{
	Time_Base t;

	t.setHour(18).setMin(20).setSec(22);
	cout<<"Universal Time";
	t.printStandard();
	cout<<endl;

	t.setTime(20,20,20).printStandard();
	cout<<endl;
}
