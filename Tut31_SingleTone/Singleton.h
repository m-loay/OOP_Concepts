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
	int m_value;
	static Singleton *s_instance;
	Singleton(int v = 0)
	{
		m_value = v;
	}
public:
	int getValue()
	{
		return m_value;
	}
	void setValue(int v)
	{
		m_value = v;
	}
	static Singleton *instance()
	{
		if (!s_instance)
			s_instance = new Singleton;
		return s_instance;
	}

};


#endif /* SINGLETON_H_ */
