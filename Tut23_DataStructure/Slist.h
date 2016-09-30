/*
 * Slist.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef SLIST_H_
#define SLIST_H_
#include <iostream>
#include "Node.h"
using namespace std;

template <typename NODETYPE>
class Slist
{
public:
	Slist();
	~Slist();
	bool insertFront(const NODETYPE &);
	bool insertBack(const NODETYPE &);
	bool removeFront();
	bool removeBack();
	int getCount ()const;
	bool isEmpty ()const;
	void print ()const;
private :
	Node <NODETYPE> *start;
	Node <NODETYPE> *end;
	Node <NODETYPE> *getNewNode(const NODETYPE &);
};

template <typename NODETYPE>
Slist<NODETYPE>::Slist()
:start(0),end(0)
 {

 }

template <typename NODETYPE>
Slist<NODETYPE>::~Slist()
{
	if(!isEmpty())
	{
		Node <NODETYPE>*current = start;
		Node <NODETYPE>*temp;

		while(current!=0)
		{
			temp = current;
			current = current->nextPtr;
			delete temp;
		}
	}
}

template <typename NODETYPE>
bool Slist<NODETYPE>::insertFront(const NODETYPE &val)
{

	Node <NODETYPE>*newNode = getNewNode(val);

	if(isEmpty())
	{
		start = end = newNode;
		return true;
	}
	else
	{
		newNode ->nextPtr = start;
		start = newNode;
		return true;
	}
	return false;
}

template <typename NODETYPE>
bool Slist<NODETYPE>::insertBack(const NODETYPE &val)
{

	Node <NODETYPE>*newNode = getNewNode(val);

	if(isEmpty())
	{
		start = end = newNode;
		return true;
	}
	else
	{
		end ->nextPtr = newNode;
		end = newNode;
		return true;
	}
	return false;
}

template <typename NODETYPE>
bool Slist<NODETYPE>::removeFront()
{
	if(isEmpty()) return false;
	Node <NODETYPE>*current = start;

	if(start == end) start = end =0;
	else start = start->nextPtr;
	delete current;
	return true;
}

template <typename NODETYPE>
bool Slist<NODETYPE>::removeBack()
{
	if(isEmpty()) return false;
	Node <NODETYPE>*current = start;

	if(start == end) start = end =0;
	else
	{
		while(current->nextPtr !=end)
		{
			current = current->nextPtr;
		}
		end = current;
		current = current ->nextPtr;
		end->nextPtr =0;
	}
	delete current;
	return true;
}

template <typename NODETYPE>
int Slist<NODETYPE>::getCount()const
{
	if(isEmpty()) return 0;
	int counter=0;
	Node <NODETYPE>*current = start;
	while (current != 0)
	{
		current = current->nextPtr;
		++counter;
	}
	return counter;
}

template <typename NODETYPE>
void Slist<NODETYPE>::print()const
{
	if(isEmpty())
	{
		cout<<"The List is Empty"<<endl;
	}
	else
	{
		Node <NODETYPE>*current = start;
		while (current != 0)
		{
			cout<<current->getData()<<" ";
			current = current->nextPtr;
		}
		cout<<endl;
	}
}

template <typename NODETYPE>
Node <NODETYPE> * Slist<NODETYPE>::getNewNode(const NODETYPE &value)
{
	return new Node<NODETYPE>(value);
}

template <typename NODETYPE>
bool Slist<NODETYPE>::isEmpty()const
{
	return start == 0;
}

#endif /* SLIST_H_ */
