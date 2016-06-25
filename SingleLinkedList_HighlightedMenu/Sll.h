/*
 * Sll.h
 *
 *  Created on: Jun 25, 2016
 *      Author: modys
 */

#ifndef SLL_H_
#define SLL_H_

#include<iostream>
#include<string>
#include "common.h"
#include "conio2.h"
#define TRUE  1
#define FALSE 0

 struct Node
{
	int value;
	struct Node *link;
};

typedef struct Node Node;
typedef Node * ptr_node;

class Sll
{
public:
	Sll();
	virtual ~Sll();
};

#endif /* SLL_H_ */
