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
	cout<<"Number of objects "<<Employee::getCount()<<endl;

	{

		Employee e1("mody", "ali");
		Employee e2("Maha", "imam");

		cout<<"Number of objects "<<Employee::getCount()<<endl;

		cout<<"e1  Name "<<e1.getFirstName()<<" " <<e1.getFLastName()<<endl;
		cout<<"e2  Name "<<e2.getFirstName()<<" " <<e2.getFLastName()<<endl;

		cout<<endl;
	}

	cout<<"Number of objects "<<Employee::getCount()<<endl;

}
