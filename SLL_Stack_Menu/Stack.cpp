/*
 * Stack.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: modys
 */

#include "Stack.h"

Stack::Stack()
{
	// TODO Auto-generated constructor stub
	singleLinkedList::setStart(NULL);
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

bool Stack::insert(int add_value)
{
	ptr_node new_node;

	/*Make a new node*/
	new_node=new Node;

	/*Test of the new node is created or not*/
	if(new_node==NULL) return FALSE;

	/*Set the value of the new block*/
	new_node->value=add_value;
	/*Make the new node points to start*/
	new_node->link=singleLinkedList::getStart();
	/*Shift the point start to point to new*/
	singleLinkedList::setStart(new_node);

	return TRUE;
}

bool Stack::remove()
{
	ptr_node temp,current;

	/*Make the a new pointer points to the head*/
	temp=singleLinkedList::getStart();
	current=singleLinkedList::getStart();

	/*Advance the head pointer to the nexr node*/
	(current)=(current)->link;
	singleLinkedList::setStart(current);
	/*Delete the node on the top (pop operation)*/
	delete(temp);
	return(TRUE);
}
