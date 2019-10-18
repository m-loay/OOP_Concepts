/*
 * Slist.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef SLIST_H_
#define SLIST_H_
#include <iostream>

#include "../Tut6_DataStructure/Node.h"
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
	int counter;
};

template <typename NODETYPE>
Slist<NODETYPE>::Slist()
:start(0),end(0),counter(0)
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
	bool result;

	if(isEmpty())
	{
		start = end = newNode;
		result = true;
		++counter;
	}
	else
	{
		newNode ->nextPtr = start;
		start = newNode;
		result = true;
		++counter;
	}
	return result;
}

template <typename NODETYPE>
bool Slist<NODETYPE>::insertBack(const NODETYPE &val)
{

	Node <NODETYPE>*newNode = getNewNode(val);
	bool result;

	if(isEmpty())
	{
		start = end = newNode;
		result = true;
		++counter;
	}
	else
	{
		end ->nextPtr = newNode;
		end = newNode;
		result = true;
		++counter;
	}
	return result;
}

template <typename NODETYPE>
bool Slist<NODETYPE>::removeFront()
{
	bool result;
	if(isEmpty())
	{
		result = false;
	}

	else
	{
		Node <NODETYPE>*current = start;

		if(start == end)
		{
			start = end =0;
			result = true;
			--counter;
		}
		else
		{
			start = start->nextPtr;
			delete current;
			result = true;
			--counter;
		}
	}
	return result;

}

template <typename NODETYPE>
bool Slist<NODETYPE>::removeBack()
{
	bool result =false;

	if(isEmpty())
	{
		result = false;
	}

	else
	{
		Node <NODETYPE>*current = start;

		if(start == end)
		{
			start = end =0;
			--counter;
		}
		else
		{
			while(current->nextPtr !=end)
			{
				current = current->nextPtr;
			}

			if(current!=0)
			{
				end = current;
				current = current ->nextPtr;
				end->nextPtr =0;
				delete current;
				result = true;
				--counter;
			}
		}

	}
	return result;
}

template <typename NODETYPE>
int Slist<NODETYPE>::getCount()const
{
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
			cout<<current->getData()<<" --> ";
			current = current->nextPtr;
		}
		cout<<"NULL"<<endl;
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
