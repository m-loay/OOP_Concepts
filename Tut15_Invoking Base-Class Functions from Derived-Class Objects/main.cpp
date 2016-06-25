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
	CommissionEmployee comEmp("Sue","Jones","33-3",1000,0.06);
	CommissionEmployee *comEmp_ptr=0;

	BasePlus baseEmp("Bob","Lewis","22-22",5000,0.04,300);
	BasePlus *baseEmp_ptr=0;

	cout<<"Commission Employee"<<endl;
	comEmp.print();

	cout<<"Base Plus"<<endl;
	baseEmp.print();

	cout<<"Assign pointers"<<endl;
	comEmp_ptr=&comEmp;
	baseEmp_ptr=&baseEmp;

	cout<<"Commission Employee pointer"<<endl;
	comEmp_ptr->print();

	cout<<"Base Plus pointer"<<endl;
	baseEmp_ptr->print();

	cout<<"Assign pointer base to derived"<<endl;
	comEmp_ptr=&baseEmp;

	cout<<"Calling print() of base throught a pointer to derived object"<<endl;
	comEmp_ptr->print();

}
