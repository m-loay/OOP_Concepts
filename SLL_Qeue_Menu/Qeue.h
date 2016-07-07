/*
 * Qeue.h
 *
 *  Created on: Jul 7, 2016
 *      Author: modys
 */

#ifndef QEUE_H_
#define QEUE_H_
#include"singleLinkedList.h"

class Qeue :public singleLinkedList
{
public:
	Qeue();
	virtual ~Qeue();

	virtual	bool insert (int);
	virtual	bool remove (void );

private:
	ptr_node end;
};

#endif /* QEUE_H_ */
