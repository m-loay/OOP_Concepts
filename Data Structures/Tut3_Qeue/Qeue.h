/*
 * Qeue.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef QEUE_H_
#define QEUE_H_

#include <iostream>

#include "../Tut3_Qeue/Node.h"
using namespace std;

template <typename NODETYPE>
class Qeue
{
public:
	Qeue();
	~Qeue();
	bool qeue (const NODETYPE &);
	bool deqeue ();
	int getCount ()const;
	void print ()const;
	bool isEmpty()const;

private:
	Node <NODETYPE> *start;
	Node <NODETYPE> *end;
	Node <NODETYPE> *getNewNode(const NODETYPE &);
	int counter;

};

template <typename NODETYPE>
Qeue<NODETYPE>::Qeue()
:start(0),end(0),counter(0)
 {

 }

template <typename NODETYPE>
Qeue<NODETYPE>::~Qeue()
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
bool Qeue<NODETYPE>::qeue(const NODETYPE &val)
{
	Node <NODETYPE> *newNode=getNewNode(val);
	bool result = false;

	if(isEmpty())
	{
		start = end = newNode;
		result = true;
		++counter;
	}
	else
	{
		end->nextPtr = newNode;
		end = newNode;
		result = true;
		++counter;
	}
	return result;
}


template <typename NODETYPE>
bool Qeue<NODETYPE>::deqeue()
{
	bool result = false;
	if(isEmpty())
	{
		result = false;
	}
	else
	{
		Node <NODETYPE> *current=start;
		if (start == end)
		{
			start = end = 0;
		}
		else
		{
			start = start->nextPtr;
		}
		delete current;
		result = true;
		--counter;
	}
	return result;
}

template <typename NODETYPE>
int Qeue<NODETYPE>::getCount()const
{
	return counter;
}


template <typename NODETYPE>
void Qeue<NODETYPE>::print()const
{
	if(isEmpty())
	{
		cout<<"Qeue is Empty"<<endl;
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
bool Qeue<NODETYPE>::isEmpty()const
{
	return start == 0;
}

template <typename NODETYPE>
Node<NODETYPE>* Qeue<NODETYPE>::getNewNode(const NODETYPE &val)
{
	return new Node<NODETYPE>(val);
}

#endif /* QEUE_H_ */
