/*
 * main.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */


#include <iostream>
#include "Qeue.h"
using namespace std;

int main ()
{
	Qeue<int> numQ;
	numQ.print();

	numQ.qeue(1);
	numQ.qeue(2);
	numQ.qeue(3);
	numQ.qeue(4);
	numQ.qeue(5);
	numQ.qeue(6);

	numQ.print();
	cout<<"number of elements in Qeue "<<numQ.getCount()<<endl;

	numQ.deqeue();
	numQ.print();
	cout<<"number of elements in Qeue "<<numQ.getCount()<<endl;

	numQ.deqeue();
	numQ.print();
	cout<<"number of elements in Qeue "<<numQ.getCount()<<endl;
}

