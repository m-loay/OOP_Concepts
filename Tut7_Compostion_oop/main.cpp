/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 *
 *      The purpose of the tutorial to understand
 *      1)using member initializer to initialze the member objects,
 *       eliminates the over-head of “doubly initializing” member objects.
 *
 *       2)constructing large objects from samll ones.
 */

#include<iostream>
#include "Date.h"
#include "Employee.h"
using namespace std;


int main()
{
	Date birth(7,1,1990,1);
	Date hire (10,1,2016,2);

	Employee swe ("Desouky","Abdelqawy",birth,hire);
	swe.print();

}

