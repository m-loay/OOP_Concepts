/*
 * main.cpp
 *
 *  Created on: Sep 24, 2016
 *      Author: modys
 */

#include <iostream>
#include "Stack.h"

using namespace std;

int main ()
{
	Stack<double>doubleStack(5);
	double value =0.0;

	cout<<"Adding data to stack"<<endl;
	while(doubleStack.push(value))
	{
		value+=1.1;
	}

	cout<<"Printing Stack"<<endl;
	doubleStack.print();

	doubleStack.pop(value);
	cout<<"Poped Value "<<value<<endl;
	doubleStack.print();
}

