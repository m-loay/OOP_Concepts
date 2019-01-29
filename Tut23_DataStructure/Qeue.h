/*
 * Qeue.h
 *
 *  Created on: Sep 25, 2016
 *      Author: modys
 */

#ifndef QEUE_H_
#define QEUE_H_

template <typename QEUETYPE>
class Qeue :private Slist<QEUETYPE>
{
public:
	bool enqeue (const QEUETYPE &val )
	{
		return (this->insertBack(val));
	}

	bool deqeue ()
	{
		return (this->removeFront());
	}

	bool isQeueEmpty ()const
	{
		return(this->isEmpty());
	}

	void printQeue()const
	{
		this->print();
	}

	int getQeueCount()const
	{
		return (this->getCount());
	}
};

#endif /* QEUE_H_ */
