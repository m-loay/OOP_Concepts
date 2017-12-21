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


	Slist<int> numS;
	Stack<int> numST;
	Qeue<int> numQ;

	/*Single linked list operation*/
	cout<<"Single linked list operation"<<endl;
	numS.insertFront(1);
	numS.insertBack(2);
	numS.insertBack(3);
	numS.insertFront(4);
	numS.insertFront(5);
	numS.print();

	numS.removeBack();
	numS.removeFront();
	numS.print();

	numS.removeBack();
	numS.print();

	/*Stack operation*/
	cout<<"Stack operation"<<endl;
	numST.push(1);
	numST.push(2);
	numST.push(3);
	numST.push(4);
	numST.push(5);
	numST.printStack();

	numST.pop();
	numST.printStack();

	numST.pop();
	numST.printStack();

	/*Qeue operation*/
	cout<<"Qeue operation"<<endl;
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


