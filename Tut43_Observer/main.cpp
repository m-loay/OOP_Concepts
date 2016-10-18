/*
 * main.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */


#include"MyObserver.h"

int main()
{
	ClockTimer timer;


	DigitalClock digitalClock(&timer);
	AnalogClock analogClock(&timer);

	timer.Tick();

	return 0;

}
