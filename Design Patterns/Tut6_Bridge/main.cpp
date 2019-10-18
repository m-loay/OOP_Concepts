/*
 * main.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#include "../Tut6_Bridge/BridgeSwitch.h"

int main()
{
	IAppliance *tv = new SonyTV("myRoom");
	Switch *s= new RemoteControl(tv);

	s->turnOn();
	s->turnOff();

	delete s;
	delete tv;
}

