/*
 * Stack.h
 *
 *  Created on: Sep 24, 2016
 *      Author: modys
 */

#ifndef STACK_H_
#define STACK_H_
#include <iostream>
using namespace std;

template< typename T> class Stack;

template< typename T>
class Stack
{
public:
	Stack(int=10);
	~Stack()
	{
		delete []stackPtr;
	}

	bool isEmpty()const
	{
		return top == -1;
	}

	bool isFull()const
	{
		return top==(size-1);
	}

	bool push (const T &);
	bool pop (T&);

	void print ()const;

private:
	int size;
	int top;
	T *stackPtr;
};

template< typename T>
Stack<T>::Stack(int s)
:size(s>0?s:10),
 top(-1),
 stackPtr(new T[size])

 {
	// TODO Auto-generated constructor stub

 }


template< typename T>
bool Stack<T>::push(const T &value)
{
	if(!isFull())
	{
		stackPtr[++top]=value;
		return true;
	}
	return false;
}


template< typename T>
bool Stack<T>::pop(T&popedValue)
{
	if(!isEmpty())
	{
		popedValue = stackPtr[top--];
		return true;
	}
	return false;
}


template< typename T>
void Stack<T>::print()const
{
	if(!isEmpty())
	{
		for(int i=0; i<top ; i++)
		{
			cout<<"element"<<i<<"/"<<size-1<<"="<<stackPtr[i]<<endl;
		}
	}
	else
	{
		cout<<"Stake is Empty"<<endl;
	}
}

#endif /* STACK_H_ */
