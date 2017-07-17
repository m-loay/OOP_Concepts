/*
 * main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 *      The purpose of the tutorial
 *      1)when using base pointer to derived object , it called the base functionality
 *        in the object only.
 *
 *       2)Using virtual functions and base pointer to derived object , the compiler
 *        construct a v-table(According to inheritance hierarchy) and call the member function
 *        associated with the object being pointed not the type of the pointer.
 */

#include <iostream>
#include<iomanip>
#include<vector>
#include "employee.h"
#include "CommissionEmployee.h"
#include "BasePlus.h"
using namespace std;

int main ()
{

	/*Create two objects from different clases*/
	CommissionEmployee cemp("Mostafa","Elbaz","123",100.0,0.1);
	BasePlus bemp ("Amr","Sabry","1234",1000,0.1,100);

	/*create pointers from base objects to derived objects*/
	CommissionEmployee *ptr_cemp=&cemp;
	BasePlus *ptr_bemp=&bemp;

	/*Use static binding to print data for both objects*/
	cout<<"Static binding"<<endl;
	cemp.print();
	bemp.print();

	/*use pointers to print
	 * base pointer to base object
	 * derived pointer to derived object*/

	cout<<"Pointer printing"<<endl;
	ptr_cemp ->print();
	ptr_bemp ->print();

  /*Using virtual function creates a v-table ,
   * when a base pointer to derived object is used ,the compiler automatically
   * selects the member function of object type (not the pointer type object) and call it.
   * */
  cout<<"Using a base pointer to derived object"<<endl;
  ptr_cemp = &bemp;
  ptr_cemp ->print();
}
