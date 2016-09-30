/*
 * main.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#include<iostream>
#include "Slist.h"
#include "Stack.h"
#include "Qeue.h"
using namespace std;

int main ()
{

	Qeue<int> numQ;
	numQ.enqeue(1);
	numQ.enqeue(2);
	numQ.enqeue(3);
	numQ.enqeue(4);
	numQ.enqeue(5);
	numQ.printQeue();

	numQ.deqeue();
	numQ.printQeue();

	numQ.deqeue();
	numQ.printQeue();

}


