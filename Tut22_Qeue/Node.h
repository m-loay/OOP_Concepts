/*
 * Node.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef NODE_H_
#define NODE_H_

template <typename NODETYPE> class Qeue;
template <typename NODETYPE>
class Node
{
	friend class Qeue<NODETYPE>;
public:
	Node(const NODETYPE &);
	NODETYPE getData()const;

private:
	NODETYPE data;
	Node <NODETYPE> *nextPtr;
};

template <typename NODETYPE>
Node<NODETYPE>::Node(const NODETYPE &val)
:data(val),nextPtr(0)
 {

 }

template <typename NODETYPE>
NODETYPE Node<NODETYPE>::getData()const
{
	return data;
}



#endif /* NODE_H_ */
