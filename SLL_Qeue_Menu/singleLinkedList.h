/*
 * Date.h
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_
#include <iostream>
using namespace std;

#define TRUE  1
#define FALSE 0

struct Node
{
	int value;
	struct Node *link;
};

typedef struct Node Node;
typedef Node * ptr_node;

class singleLinkedList
{
public:

	singleLinkedList();
	virtual ~singleLinkedList();

	ptr_node getStart (void)const
	{
		return start;
	}
	void setStart (ptr_node s)
	{
		start=s;
	}


	virtual	bool insert (int);
	virtual	bool remove (int );
	bool find (int add_value) ;
	bool isEmpty()const;
	int getCount ();
	void print()const;
	virtual void freeList();

private:
	ptr_node start;
};

#endif /* SINGLELINKEDLIST_H_ */
