/*
 * main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 *      The purpose of the tutorial
 *
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
	BasePlus baseEmp("Samer","Saber","22-22",5000,0.04,300);
    BasePlus *baseEmp_ptr=0;

	//Assign a base class pointer to derived object
	comEmp_ptr=&baseEmp;

	cout<<comEmp_ptr->getFirstName()<<' '<<comEmp_ptr->getLastName()<<endl;

  //Calling earning using base pointer object
  //earning = getComissionRate() * getGrossSales();
  cout<<"Calling earning using base pointer object"<<endl;
  cout<<comEmp_ptr->earnings()<<endl;

  //Calling earning using derived pointer object
  //earning= getBaseSalary() + CommissionEmployee::earnings();
  cout<<"Calling earning using derived pointer object"<<endl;
  baseEmp_ptr=&baseEmp;
  cout<<baseEmp_ptr->earnings()<<endl;


  //This will generate an error to call member calss not inherited from base class
  //comEmp_ptr->setsetBaseSalaray(400);


}
