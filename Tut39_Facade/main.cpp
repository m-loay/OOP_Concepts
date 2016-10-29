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
	Facade shapeMaker;

	shapeMaker.drawCircle();
	shapeMaker.drawRectangle();
	shapeMaker.drawSquare();

    return 0;
}
