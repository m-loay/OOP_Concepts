/*
 * main.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#include <iostream>
#include <string>
using namespace std;
#include "../Tut8_Facade/Facade.h"


int main()
{
	/*Create object of Facade*/
	Facade shapeMaker;

	/*Use this object to control the other object functionalties*/
	shapeMaker.drawCircle();
	shapeMaker.drawRectangle();
	shapeMaker.drawSquare();

    return 0;
}
