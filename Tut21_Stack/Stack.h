/*
 * Stack.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "Node.h"

using namespace std;

template <typename NODETYPE>
class Stack
{
public:
	Stack();
	~Stack();
	bool push (const NODETYPE &);
	bool pop ();
	int getCount ()const;
	void print ()const;
	bool isEmpty()const;

private:
	Node <NODETYPE> *start;
	Node <NODETYPE> *getNewNode(const NODETYPE &);
};

template <typename NODETYPE>
Stack<NODETYPE>::Stack()
:start(0)
{

}

template <typename NODETYPE>
Stack<NODETYPE>::~Stack()
{

	if(!isEmpty())
	{
		Node <NODETYPE> *current=start;
		Node <NODETYPE> *temp=0;

		while(current!=0)
		{
			temp = current;
			current = current->nextPtr;
			delete temp;
		}
	}
}

template <typename NODETYPE>
bool Stack<NODETYPE>::push(const NODETYPE &val)
{
	Node <NODETYPE> *newNode=getNewNode(val);
	if(isEmpty())
	{
		start = newNode;
		return true;
	}
	else
	{
		newNode->nextPtr = start;
		start = newNode;
		return true;
	}
	return false;
}

template <typename NODETYPE>
bool Stack<NODETYPE>::pop()
{
	if(isEmpty()) return false;
	Node <NODETYPE> *current=start;
	start = start->nextPtr;
	delete current;
	return true;
}

template <typename NODETYPE>
int Stack<NODETYPE>::getCount()const
{
	if(isEmpty())return 0;
	Node <NODETYPE> *current=start;
	int counter=0;
	while(counter!=0)
	{
		++counter;
		current = current->nextPtr;
	}
	return counter;
}


template <typename NODETYPE>
void Stack<NODETYPE>::print()const
{
	if(isEmpty())return;
	Node <NODETYPE> *current=start;
	while(current!=0)
	{
		cout<<current->data<<" ";
		current=current->nextPtr;
	}
	cout<<endl;
}

template <typename NODETYPE>
bool Stack<NODETYPE>::isEmpty()const
{
	return start == 0;
}

template <typename NODETYPE>
Node<NODETYPE>* Stack<NODETYPE>::getNewNode(const NODETYPE &val)
{
	return new Node<NODETYPE>(val);
}

#endif /* STACK_H_ */
