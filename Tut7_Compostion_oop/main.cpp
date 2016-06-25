/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include<iostream>
#include"Date.h"
#include "Employee.h"

using namespace std;

int main()
{
	Date birth_manager(7,24,1980);
	Date hire_manager (3,12,2000);

	Employee manager("mody", "Ali", birth_manager, hire_manager);

	cout<<endl;
	manager.print();

	cout<<"Two additional Destructor because Date is a member object in Employee"
			<<"\n So object date copy it self by Default copy Constructor "<<endl;

}
