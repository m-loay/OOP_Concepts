/*
 * main.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#include<iostream>
#include "Slist.h"
using namespace std;

int main ()
{
	Slist<int>numList;
	numList.insert(3);
	numList.insert(1);
	numList.insert(5);
	numList.insert(6);
	numList.insert(7);
	numList.insert(8);
	numList.insert(2);

	numList.print();
	numList.remove(3);

	numList.print();
	cout<<"number of Elements"<<numList.getCount()<<endl;



}


