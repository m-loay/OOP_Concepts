/*
 * main.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#include<iostream>
#include "Dlist.h"
#include "Node.h"
using namespace std;

int main ()
{
	Dlist<int>numList;
	numList.insertFront(8);
	numList.insertFront(7);
	numList.insertFront(6);
	numList.insertFront(5);
	numList.insertFront(4);
	numList.insertFront(3);
	numList.insertFront(2);
	numList.insertFront(1);

	numList.print();

	numList.removeBack();numList.removeBack();numList.removeBack();
	numList.print();
	Node <int> *current = numList.getStart();

	cout<<"Element 5 "<<(numList.find(current,10)?"has ":"has not ")<<"found"<<endl;

}


