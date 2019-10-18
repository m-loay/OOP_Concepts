/*
 * main.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#include <iostream>

#include "../Tut2_Stack/Stack.h"
using namespace std;

int main ()
{
	Stack<int>numStack;
	numStack.print();

	numStack.push(5);
	numStack.push(3);
	numStack.push(6);
	numStack.push(8);
	numStack.push(9);
	numStack.push(1);

	numStack.print();
	cout<<"number of elements in Stack "<<numStack.getCount()<<endl;

	numStack.pop();
	numStack.print();
	cout<<"number of elements in Stack "<<numStack.getCount()<<endl;

	numStack.pop();
	numStack.print();
	cout<<"number of elements in Stack "<<numStack.getCount()<<endl;

}


