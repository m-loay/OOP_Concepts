/*
 * main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
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

	/*Print base pointer to derived object invokes base functionality in derived object*/
	cout<<"Using a base pointer to derived object"<<endl;
	ptr_cemp = &bemp;
	ptr_cemp ->print();


}
