/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include<iostream>
#include "Increment.h"// include definition of class Increment
using namespace std;


int main ()
{
	Increment value(10,5);

	cout<<"before Increment"<<endl;
	value.print();

	for (int var = 0; var < 3; var++)
	{
		value.addIncrement();
		cout<<"After Increment j= "<<var<<endl;
		value.print();

	}
}
