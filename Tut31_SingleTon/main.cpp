/*
 * main.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: modys
 */

#include <iostream>
#include "GlobalClassS.h"
#include "Singleton.h"
using namespace std;

// Default initialization
Singleton *Singleton::s_instance = 0;

int main()
{
	/*Using object from singleTon class results in compilation error
	because the constructor of the class is private and can not be accessed.
	*/
	// Singleton sObject;
	// sObject.setValue(2);
	// sObject.printSingleTon();

	/*To access the private constructor , a static member function is used to access
	the class member function through static member , 
	which grantees that no more than one object can be created from this class.
	*/
	Singleton::getinstance()->setValue(5);
	Singleton::getinstance()->printSingleTon();
}
