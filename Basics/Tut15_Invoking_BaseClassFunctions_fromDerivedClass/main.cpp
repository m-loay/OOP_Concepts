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
	CommissionEmployee comEmp("Mohamed","Fahmy","33-3",1000,0.06);
	CommissionEmployee *comEmp_ptr=0;

	BasePlus baseEmp("Gabreeal","Saber","22-22",5000,0.04,300);
	BasePlus *baseEmp_ptr=0;

	/*Print the data in all objects*/
	cout<<"\n ----Commission Employee----\n"<<endl;
	comEmp.print();

	cout<<"\n----Base Plus----\n"<<endl;
	baseEmp.print();

	/*Assign each pointer to its equavlent object*/
	cout<<"\n----Assign pointers----\n"<<endl;
	comEmp_ptr=&comEmp;
	baseEmp_ptr=&baseEmp;

	/*A base class pointer to a base class object invoke base class functionality */
	cout<<"\n----Commission Employee pointer----\n"<<endl;
	comEmp_ptr->print();

	/*A derive class pointer to a Derived class object invoke derived class functionality */
	cout<<"\n----Base Plus pointer----\n"<<endl;
	baseEmp_ptr->print();

	/*A base class pointer to a Derived class object invoke base class functionality in derived object */
	cout<<"\n----Assign pointer base to derived----\n"<<endl;
	comEmp_ptr=&baseEmp;

	cout<<"\n ----Calling print() of base throught a pointer to derived object----\n"<<endl;
	comEmp_ptr->print();

}
