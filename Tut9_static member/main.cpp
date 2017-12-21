/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include<iostream>
#include "Employee.h"

using namespace std;

int main()
{
	/*Use the getter static member function to print number of created objects*/
	cout<<"Number of objects "<<Employee::getCount()<<endl;

	{
		/*Create two objects*/
		Employee e1("Ahmed", "Eissa");
		Employee e2("Samer", "Amgad");

		/*Print number of objects*/
		cout<<"Number of objects "<<Employee::getCount()<<endl;

		cout<<"e1  Name "<<e1.getFirstName()<<" " <<e1.getFLastName()<<endl;
		cout<<"e2  Name "<<e2.getFirstName()<<" " <<e2.getFLastName()<<endl;

		cout<<endl;
	}

	/*Print number of objects*/
	cout<<"Number of objects "<<Employee::getCount()<<endl;
}
