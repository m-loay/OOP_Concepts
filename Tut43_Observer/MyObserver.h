/*
 * MyObserver.h
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#ifndef MYOBSERVER_H_
#define MYOBSERVER_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>
using namespace std;

class ASubject;
class IObserver
{
public:
	IObserver()
	{
		cout <<"IOberver called"<<endl;
	}
	virtual ~IObserver()
	{
		cout <<"~IOberver called"<<endl;
	}
	virtual void Update(ASubject *theChangeSubject) = 0;
};



class ASubject
{
	//Lets keep a track of all the shops we have observing
	vector<IObserver*> list;

public:
	ASubject()
{
		cout <<"ASubject called"<<endl;
}
	virtual ~ASubject()
	{
		cout <<"~ASubject called"<<endl;
	}
	virtual void Attach(IObserver *o)
	{
		list.push_back(o);
	}
	virtual void Detach(IObserver *o)
	{
		 int count = list.size();
		 int i;

		 for (i = 0; i < count; i++) {
		   if(list[i] == o)
		   break;
		 }
		 if(i < count)
			 list.erase(list.begin() + i);
	}
	virtual void Notify()
	{
		for(vector<IObserver*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
		{
			if(*iter != 0)
			{
				(*iter)->Update(this);
			}
		}
	}
};

class ClockTimer : public ASubject
{
public:
	ClockTimer()
{
		_strtime( tmpbuf );
		cout <<"ClockTimer called"<<endl;
}

	~ClockTimer()
	{
		cout <<"~ClockTimer called"<<endl;
	}

	int GetHour()
	{
		char timebuf[128];
		strncpy(timebuf, tmpbuf, 2);
		timebuf[2] = NULL;

		return atoi(timebuf);
	}
	int GetMinute()
	{
		char timebuf[128];
		strncpy(timebuf, tmpbuf+3, 2);
		timebuf[2] = NULL;

		return atoi(timebuf);
	}
	int GetSecond()
	{
		char timebuf[128];
		strncpy(timebuf, tmpbuf+6, 2);
		timebuf[2] = NULL;

		return atoi(timebuf);
	}
	void Tick()
	{
		_tzset();
		_strtime( tmpbuf );
		Notify();
	}
private:
	char tmpbuf[128];
};

class DigitalClock: public IObserver
{
public:
	DigitalClock(ClockTimer *s)
{
		_subject = s;
		_subject->Attach(this);
		cout <<"DigitalClock called"<<endl;
}
	~DigitalClock()
	{
		_subject->Detach(this);
		cout <<"~DigitalClock called"<<endl;
	}
	void Update(ASubject *theChangedSubject)
	{
		if(theChangedSubject == _subject)
			Draw();
	}
	void Draw()
	{
		int hour = _subject->GetHour();
		int minute = _subject->GetMinute();
		int second = _subject->GetSecond();

		cout << "Digital time is " << hour << ":"
				<< minute << ":"
				<< second << endl;
	}
private:
	ClockTimer *_subject;
};

class AnalogClock: public IObserver
{
public:
	AnalogClock(ClockTimer *s)
{
		_subject = s;
		 _subject->Attach(this);
			cout <<"AnalogClock called"<<endl;

}
	~AnalogClock()
	{
		 _subject->Detach(this);
		 cout <<"~AnalogClock called"<<endl;
	}
	void Update(ASubject *theChangedSubject)
	{
		 if(theChangedSubject == _subject)
		  Draw();
	}
	void Draw()
	{
		int hour = _subject->GetHour();
		 int minute = _subject->GetMinute();
		 int second = _subject->GetSecond();

		 cout << "Analog time is " << hour << ":"
		         << minute << ":"
		         << second << endl;
	}
private:
	ClockTimer *_subject;
};

#endif /* MYOBSERVER_H_ */
