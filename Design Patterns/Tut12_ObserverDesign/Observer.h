/*
 * Observer.h
 *
 *  Created on: Oct 27, 2016
 *      Author: modys
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_
#include <vector>
#include<iostream>
using namespace std;

class Subject;

class Observer
{
public:
	Observer():sub(0)
	{
		cout<<"Observer Called"<<endl;
	}
	virtual ~Observer()
	{
		cout<<"~Observer Called"<<endl;
	}

	virtual void update()=0;
protected:
	Subject *sub;

};

class Subject
{
public:
	Subject():state(0)
	{

		cout<<"Subject Called"<<endl;

	}
	~Subject()
	{
		cout<<"~Subject Called"<<endl;
	}

	int getState()const
	{
		return state;
	}

	void setState(int s)
	{
		state = s;
		notifyAll();
	}

	void attachObs (Observer * ob)
	{
		observers.push_back(ob);
	}

private:
	vector<Observer*>observers;
	int state;

	void notifyAll ()
	{
		for(vector<Observer*>::const_iterator iter = observers.begin(); iter != observers.end(); ++iter)
		{
			if(*iter!=0)
			{
				(*iter)->update();
			}
		}
	}
};



class ObsOne:public Observer
{
public:
	ObsOne(Subject *s)
	{
		cout<<"ObsOne Called"<<endl;
		sub = s;
		sub->attachObs(this);
	}
	virtual ~ObsOne()
	{
		cout<<"~ObsOne Called"<<endl;
	}

	void update()
	{
		cout<<"ObsOne state+1 ="<<((sub->getState())+1)<<endl;
	}

};

class ObsTwo:public Observer
{
public:
	ObsTwo(Subject *s)
	{
		cout<<"ObsTwo Called"<<endl;
		sub = s;
		sub->attachObs(this);
	}
	virtual ~ObsTwo()
	{
		cout<<"~ObsTwo Called"<<endl;
	}

	void update()
	{
		cout<<"~ObsOne state+2 ="<<((sub->getState())+2)<<endl;
	}

};


class ObsThree:public Observer
{
public:
	ObsThree(Subject *s)
	{
		cout<<"ObsThree Called"<<endl;
		sub = s;
		sub->attachObs(this);
	}
	virtual ~ObsThree()
	{
		cout<<"ObsThree Called"<<endl;
	}

	void update()
	{
		cout<<"~ObsOne state+3 ="<<((sub->getState())+3)<<endl;
	}

};
#endif /* OBSERVER_H_ */
