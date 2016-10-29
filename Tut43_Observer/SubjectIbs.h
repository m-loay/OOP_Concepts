/*
 * SubjectIbs.h
 *
 *  Created on: Oct 26, 2016
 *      Author: modys
 */

#ifndef SUBJECTIBS_H_
#define SUBJECTIBS_H_
#include<iostream>
#include <vector>
using namespace std;

class SubjectObs
{
public:
	SubjectObs():state(0)
	{
		cout<<"SubjectObs Called"<<endl;

	}
	~SubjectObs()
	{
		cout<<"~SubjectObs Called"<<endl;
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
		for(unsigned int i=0; i<observers.size();i++)
		{
			//observers[i]->update();
		}
	}
};

#endif /* SUBJECTIBS_H_ */
