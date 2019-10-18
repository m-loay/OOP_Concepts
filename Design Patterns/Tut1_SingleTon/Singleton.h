/*
 * Singleton.h
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <iostream>
using namespace std;

class Singleton
{
	public:
	static Singleton *getinstance()
	{
		if (!s_instance)
			s_instance = new Singleton;
		return s_instance;
	}

	~Singleton()
	{
		cout<<"SingleTon destructor called"<<endl;
	}

	int getValue()
	{
		return m_value;
	}

	void setValue(int v)
	{
		m_value = v;
	}

	void printSingleTon(void)
	{
		cout<<"objectValue="<<m_value<<endl;
	}

	private:
	int m_value;
	static Singleton *s_instance;
	Singleton(int v = 0)
	{
		cout<<"SingleTon constructor called"<<endl;
		m_value = v;
	}
};


#endif /* SINGLETON_H_ */
