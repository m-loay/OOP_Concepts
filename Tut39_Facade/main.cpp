/*
 * main.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#include <iostream>
#include <string>
using namespace std;
#include "Facade.h"


int main()
{
	/*Create object of gacade*/
	Facade shapeMaker;

	/*Use this object to control the other object functionalties*/
	shapeMaker.drawCircle();
	shapeMaker.drawRectangle();
	shapeMaker.drawSquare();

    return 0;
}
