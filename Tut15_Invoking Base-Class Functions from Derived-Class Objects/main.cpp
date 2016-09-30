/*
 * main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#include <iostream>
#include "CommissionEmployee.h"
#include "BasePlus.h"
using namespace std;

int main ()
{
	/*Create instance of Base class and derived Class with a pointer of each*/
	CommissionEmployee comEmp("Sue","Jones","33-3",1000,0.06);
	CommissionEmployee *comEmp_ptr=0;

	BasePlus baseEmp("Bob","Lewis","22-22",5000,0.04,300);
	BasePlus *baseEmp_ptr=0;

	/*Print the data in all objects*/
	cout<<"Commission Employee"<<endl;
	comEmp.print();

	cout<<"Base Plus"<<endl;
	baseEmp.print();

	/*Assign each pointer to its equavlent object*/
	cout<<"Assign pointers"<<endl;
	comEmp_ptr=&comEmp;
	baseEmp_ptr=&baseEmp;

	/*A base class pointer to a base class object invoke base class functionality */
	cout<<"Commission Employee pointer"<<endl;
	comEmp_ptr->print();

	/*A derive class pointer to a Derived class object invoke derived class functionality */
	cout<<"Base Plus pointer"<<endl;
	baseEmp_ptr->print();

	/*A base class pointer to a Derived class object invoke base class functionality in derived object */
	cout<<"Assign pointer base to derived"<<endl;
	comEmp_ptr=&baseEmp;

	cout<<"Calling print() of base throught a pointer to derived object"<<endl;
	comEmp_ptr->print();

}
