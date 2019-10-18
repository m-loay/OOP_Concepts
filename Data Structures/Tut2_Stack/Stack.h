  /*
 * Stack.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

#include "../Tut2_Stack/Node.h"

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
	int counter;
};

template <typename NODETYPE>
Stack<NODETYPE>::Stack()
:start(0),counter(0)
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
	bool result =false;
	if(isEmpty())
	{
		start = newNode;
		result= true;
		++counter;
	}
	else
	{
		newNode->nextPtr = start;
		start = newNode;
		result = true;
		++counter;
	}
	return result;
}

template <typename NODETYPE>
bool Stack<NODETYPE>::pop()
{
	bool result;
	if(isEmpty())
	{
		result = false;
	}
	else
	{
		Node <NODETYPE> *current=start;
		start = start->nextPtr;
		delete current;
		result = true;
		--counter;
	}
	return result;
}

template <typename NODETYPE>
int Stack<NODETYPE>::getCount()const
{
	return counter;
}


template <typename NODETYPE>
void Stack<NODETYPE>::print()const
{
	if(isEmpty())
	{
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		Node <NODETYPE> *current=start;
		while(current!=0)
		{
			cout<<current->data<<" --> ";
			current=current->nextPtr;
		}
		cout<<"NULL"<<endl;
	}
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
