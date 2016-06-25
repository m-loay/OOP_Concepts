/*
 * main.cpp
 *
 *  Created on: Jun 19, 2016
 *      Author: modys
 */

#include<iostream>
#include "PhoneNumber.h"
using namespace std;

int main ()
{
	PhoneNumber phone;

	cout<<"Enter your first and last Name";
	/*operator>>( cin, phone );*/
	cin>>phone;

	cout<<"your entered ";
	/*operator<<( cout, phone );*/
	cout<<phone;
}
