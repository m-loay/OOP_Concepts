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
	//create base class pointer
	CommissionEmployee *comEmp_ptr=0;

	//create object from derived class
	BasePlus baseEmp("Bob","Lewis","22-22",5000,0.04,300);

	//Assign a base class pointer to derived object
	comEmp_ptr=&baseEmp;

	cout<<comEmp_ptr->getFirstName()<<' '<<comEmp_ptr->getLastName()<<endl;


	//This will generate an error to call member calss not inherited from base class
	//double baseSalary=comEmp_ptr->getbaseSalar();


}
