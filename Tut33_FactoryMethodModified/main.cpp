/*
 * main.cpp<<
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#include <iostream>
#include <vector>
#include "Widget.h"
#include "Client.h"
using namespace std;

int main()
{

	Factory *factory;
#ifdef LINUX
	factory = new LinuxFactory;
#else // WINDOWS
	factory = new WindowsFactory;
#endif

	{
		Client *c = new Client(factory);
		c->draw();
	}
	delete factory;


	cout<<endl;

}

