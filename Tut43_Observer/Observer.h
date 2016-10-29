/*
 * Observer.h
 *
 *  Created on: Oct 26, 2016
 *      Author: modys
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "SubjectIbs.h"
using namespace std;

class Observer
{
public:
	Observer():subject(0)
	{
		cout<<"Observer Called"<<endl;
	}
	virtual ~Observer()
	{
		cout<<"~Observer Called"<<endl;
	}

	virtual void update()=0;

	SubjectObs *subject;
};






#endif /* OBSERVER_H_ */
