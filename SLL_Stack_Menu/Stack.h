/*
 * Stack.h
 *
 *  Created on: Jul 7, 2016
 *      Author: modys
 */

#ifndef STACK_H_
#define STACK_H_
#include"singleLinkedList.h"
using namespace std;

class Stack: public singleLinkedList
{
public:
	Stack();
	virtual ~Stack();

	virtual	bool insert (int);
	virtual	bool remove (void );

};

#endif /* STACK_H_ */
