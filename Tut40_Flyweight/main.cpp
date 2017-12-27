/*
 * main.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#include "FlyWeight.h"

string colours[5] = {"Red", "Green", "Blue", "White", "Black"};

int main()
{
	/*Create many objects and check the objects with same coulour wont be created again*/
	Circle *circleR1 = FlyWeight::getCircle(colours[0]);
	circleR1 ->setX(10);
	circleR1->setY(10);
	circleR1->setRadius(5);
	circleR1->draw();

	Circle *circleR2 = FlyWeight::getCircle(colours[0]);
	circleR2 ->setX(20);
	circleR2->setY(20);
	circleR2->setRadius(10);
	circleR2->draw();

	Circle *circleR3 = FlyWeight::getCircle(colours[0]);
	circleR3 ->setX(30);
	circleR3->setY(30);
	circleR3->setRadius(20);
	circleR3->draw();

	Circle *circleG1 = FlyWeight::getCircle(colours[1]);
	circleG1 ->setX(10);
	circleG1->setY(10);
	circleG1->setRadius(5);
	circleG1->draw();

	Circle *circleG2 = FlyWeight::getCircle(colours[1]);
	circleG2 ->setX(20);
	circleG2->setY(20);
	circleG2->setRadius(10);
	circleG2->draw();

	Circle *circleG3 = FlyWeight::getCircle(colours[1]);
	circleG3 ->setX(30);
	circleG3->setY(30);
	circleG3->setRadius(20);
	circleG3->draw();

	Circle *circleR4 = FlyWeight::getCircle(colours[0]);
	circleR4 ->setX(40);
	circleR4->setY(40);
	circleR4->setRadius(30);
	circleR4->draw();

}

