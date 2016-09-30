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
	bool insert(const NODETYPE &);
	bool remove(const NODETYPE &);
	int getCount ()const;
	bool isEmpty ()const;
	void print ()const;
private :
	Node <NODETYPE> *start;
	Node <NODETYPE> *getNewNode(const NODETYPE &);
};

template <typename NODETYPE>
Slist<NODETYPE>::Slist()
:start(0)
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
bool Slist<NODETYPE>::insert(const NODETYPE &val)
{

	Node <NODETYPE>*newNode = getNewNode(val);
	Node <NODETYPE>*current = start;
	Node <NODETYPE>*prev = 0;

	if(isEmpty())
	{
		start = newNode;
	}
	else
	{
		while(current!=0 && current->data <val)
		{
			prev = current;
			current= current->nextPtr;
		}
		newNode->nextPtr = current;

		if(prev == 0) start = newNode;
		else prev->nextPtr = newNode;
		return true;
	}
	return false;
}


template <typename NODETYPE>
bool Slist<NODETYPE>::remove(const NODETYPE &delValue)
{
	if(isEmpty()) return false;

	if(delValue == start->data)
	{
		Node <NODETYPE>*current = start;
		start = start->nextPtr;
		delete current;
		return true;
	}
	else
	{
		Node <NODETYPE>*current = start;
		Node <NODETYPE>*prev = 0;

		while(current!= 0 && current->data != delValue)
		{
			prev = current;
			current = current->nextPtr;
		}

		if(current != 0)
		{
			prev->nextPtr = current->nextPtr;
			delete current;
			return true;
		}
	}
	return false;
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
