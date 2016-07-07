/*
 * Qeue.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: modys
 */

#include "Qeue.h"

Qeue::Qeue()
{
	// TODO Auto-generated constructor stub
	end=NULL;

}

Qeue::~Qeue() {
	// TODO Auto-generated destructor stub
}

bool Qeue::insert(int add_value)
{
	ptr_node new_node;
	new_node=new Node;

	if(new_node == NULL) return(FALSE);

	/*Assign the value of the node , then make it to points to NUll (queue)*/
	new_node->value=add_value;
	new_node->link=NULL;

	/*
	 * if the queue is empty , head pointer should points to first element in queue
	 * if not we should make the last element in the queue points to the new node
	 * make the end pointer points to the last new element
	 * */
	if(singleLinkedList::getStart()== NULL) singleLinkedList::setStart(new_node);
	else (end->link)=new_node;
	end=new_node;
	return(TRUE);
}

bool Qeue::remove(void)
{
	ptr_node temp;
	ptr_node current;

	/*Make the a new pointer points to the head*/
	temp=singleLinkedList::getStart();
	current=singleLinkedList::getStart();

	/*Advance the head pointer to the nexr node*/
	current=current->link;
	singleLinkedList::setStart(current);
	/*Delete the node on the top (dequeue operation)*/
	delete(temp);
	return(TRUE);

}
