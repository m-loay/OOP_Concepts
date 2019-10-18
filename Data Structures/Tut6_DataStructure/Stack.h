/*
lkkkkkkkk.            * Stack.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef STACK_H_
#define STACK_H_

#include "../Tut6_DataStructure/Slist.h"

template< typename STACKTYPE >
class Stack :private Slist<STACKTYPE>
{
public:
	bool push (const STACKTYPE &data)
	{
		return(this->insertFront(data));
	}

	bool pop ()
	{
		return (this->removeFront());
	}

	bool isStackEmpty ()const
	{
		return this ->isEmpty();
	}

	void printStack ()const
	{
		this->print();
	}

	int getStackCount()const
	{
		return (this->getCount());
	}
};



#endif /* STACK_H_ */
