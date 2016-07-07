/*
 * Date.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include <iostream>

#include "singleLinkedList.h"
using namespace std;

singleLinkedList::singleLinkedList()
{
	start=NULL;
	cout << "singleLinkedList object Constructor for date ";
}


singleLinkedList::~singleLinkedList()
{
	// TODO Auto-generated destructor stub
	cout << "singleLinkedList object destructor for date "<< endl;

}



bool singleLinkedList::insert(int add_value)
{
	/*Make pointers to traverse the list and locate new block*/
	ptr_node current,new_node,prev;

	/*Make the first pointer points to the head of the list*/
	current=start;

	/*Make the second pointer points to ntg*/
	prev=NULL;

	/*Make a loop to traverse the list and stops only in two cases
	 * 1)End of list at NULL
	 * 2)when the new value is bigger than current value
	 * */

	while(current!=NULL && current->value<add_value)
	{
		/*Advance the prev to current location*/
		prev=current;
		/*Advance the current to next node*/
		current=current->link;
	}

	/*Make a new node*/
	new_node=new Node;

	/*Test of the new node is created or not*/
	if(new_node==NULL) return FALSE;

	/*Set the value of the new block*/
	new_node->value=add_value;
	/*Connect the new node with next node*/
	new_node->link=current;

	/*Check if the inserted node at first or at middle
	 * if at first the pointer head start should point to new node
	 * else the prev node should point to new node
	 * */
	if(prev==NULL) start=new_node;
	else prev->link=new_node;
	return TRUE;
}

bool singleLinkedList::remove(int deleted_value)
{
	ptr_node prev,current,temp;
	current=start;

	if(deleted_value==(current)->value)
	{
		temp=(current);
		(current)=(current)->link;
		delete(temp);
		return(TRUE);
	}

	else
	{


		/*Make the second pointer points to ntg*/
		prev=NULL;

		/*Make a loop to traverse the list and stops only in two cases
		 * 1)End of list at NULL
		 * 2)the deleted value is found
		 * */

		while(current!=NULL && current->value!=deleted_value)
		{
			/*Advance the prev to current location*/
			prev=current;
			/*Advance the current to next node*/
			current=current->link;
		}

		if(current!=NULL)
		{
			temp=current;
			prev->link=current->link;
			delete(temp);
			return(TRUE);
		}
	}
	return(FALSE);
}

bool singleLinkedList::find(int add_value)
{
	ptr_node current=start;
	while((current)!=NULL)
	{
		if((current)->value==add_value)
			return TRUE;
		(current)=(current)->link;
	}

	return FALSE;
}

bool singleLinkedList::isEmpty()const
{
	return (start)==NULL;
}

int singleLinkedList::getCount()
{
	ptr_node current=start;
	int counter=0;
	while((current)!=NULL)
	{
		(current)=(current)->link;
		counter++;
	}

	return(counter);
}

void singleLinkedList::print()const
{
	ptr_node current=start;
	while((current)!=NULL)
	{
		cout<<(current)->value<<" --> ";
		(current)=(current)->link;
	}
	cout<<" NULL\n";
}

void singleLinkedList::freeList()
{

	if((start)!=NULL)
	{
		delete (start);
	}
	(start)=NULL;
}
