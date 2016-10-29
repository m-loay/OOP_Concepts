/*
 * OsFactory.h
 *
 *  Created on: Oct 23, 2016
 *      Author: modys
 */

#ifndef OSFACTORY_H_
#define OSFACTORY_H_
#include "Widget.h"
using namespace std;

class OsFactory
{
public:
	OsFactory()
{
		cout<<"OsFactory called"<<endl;
}
	virtual ~OsFactory()
	{
		cout<<"~OsFactory called"<<endl;
	}

	static Factory *getOsComponents(int choice)
	{
		switch (choice)
		{
		case 1:
			return new LinuxFactory;
			break;

		case 2:
			return new WindowsFactory;
			break;

		default:
			return 0;
			break;
		}
	}

};

#endif /* OSFACTORY_H_ */
