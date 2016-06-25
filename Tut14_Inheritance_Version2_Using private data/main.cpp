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
	BasePlus emp("mody", "Ali", "777", 5000, 0.04, 300);
	emp.print();
}
