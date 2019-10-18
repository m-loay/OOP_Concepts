/*
 * main.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: modys
 */


#include <iostream>

#include "../Tut12_ObserverDesign/Observer.h"
using namespace std;

int main()
{
	Subject *object = new Subject;
	Observer *one=new ObsOne(object);
	Observer *two=new ObsTwo(object);
	Observer *three=new ObsThree(object);
	object->setState(1);
	object ->setState(2);
	object ->setState(3);

	delete three;
	delete two;
	delete one;
	delete object;
}


