/*
 * main.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#include<iostream>

#include "../Tut6_DataStructure/Qeue.h"
#include "../Tut6_DataStructure/Slist.h"
#include "../Tut6_DataStructure/Stack.h"
using namespace std;

int main ()
{


	Slist<int> numS;
	Stack<int> numST;
	Qeue<int> numQ;

	/*Single linked list operation*/
	cout<<"\n/***Single linked list operation***/"<<endl;
	numS.print();
	cout<<"Number of elements --> "<<numS.getCount()<<endl;
	numS.insertFront(1);
	numS.insertBack(2);
	numS.insertBack(3);
	numS.insertFront(4);
	numS.insertFront(5);
	numS.print();
	cout<<"Number of elements --> "<<numS.getCount()<<endl;

	numS.removeBack();
	numS.removeFront();
	numS.print();
	cout<<"Number of elements --> "<<numS.getCount()<<endl;

	numS.removeBack();
	numS.print();
	cout<<"Number of elements --> "<<numS.getCount()<<endl;

	/*Stack operation*/
	cout<<"\n/***Stack operation***/"<<endl;
	numST.printStack();
	cout<<"Number of elements --> "<<numST.getStackCount()<<endl;
	numST.push(1);
	numST.push(2);
	numST.push(3);
	numST.push(4);
	numST.push(5);
	numST.printStack();
	cout<<"Number of elements --> "<<numST.getStackCount()<<endl;

	numST.pop();
	numST.printStack();
	cout<<"Number of elements --> "<<numST.getStackCount()<<endl;

	numST.pop();
	numST.printStack();
	cout<<"Number of elements --> "<<numST.getStackCount()<<endl;

	/*Qeue operation*/
	cout<<"\n/***Qeue operation***/"<<endl;
	numQ.printQeue();
	cout<<"Number of elements --> "<<numQ.getQeueCount()<<endl;
	numQ.enqeue(1);
	numQ.enqeue(2);
	numQ.enqeue(3);
	numQ.enqeue(4);
	numQ.enqeue(5);
	numQ.printQeue();
	cout<<"Number of elements --> "<<numQ.getQeueCount()<<endl;

	numQ.deqeue();
	numQ.printQeue();
	cout<<"Number of elements --> "<<numQ.getQeueCount()<<endl;

	numQ.deqeue();
	numQ.printQeue();
	cout<<"Number of elements --> "<<numQ.getQeueCount()<<endl;
}


