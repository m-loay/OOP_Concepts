/*
 * main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 *      The purpose of the tutorial
 *      1)The base class object pointer can be assigned to derived object,
 *        but can only invoke base class functionality in the derived object.
 *
 *      2)In inheritance , the derived class can overridden a definition of
 *       a member function of base class
 *
 *      3)A member function of base class can be called in derived class
 *        baseClassName::function name , as it appears in earning member function.
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
