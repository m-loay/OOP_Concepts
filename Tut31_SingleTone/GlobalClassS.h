/*
 * GlobalClassS.h
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#ifndef GLOBALCLASSS_H_
#define GLOBALCLASSS_H_
#include <iostream>
using namespace std;
class GlobalClassS {
public:
GlobalClassS(int v=0,int iden=0)
{
		m_value = v;
		id = iden;
		cout<<"constructor of object"<<id<<"is called"<<endl;
}

~GlobalClassS()
{
	cout<<"destructor of object"<<id<<"is called"<<endl;
}

int getValue()const
{
	return m_value;
}

void setValue(int v , int ident)
{
	m_value = v;
	id = ident;
}

private:
	int m_value;
	int id;
};

#endif /* GLOBALCLASSS_H_ */
