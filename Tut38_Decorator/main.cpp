/*
 * main.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: modys
 */
#include "ShapeDecorator.h"

int main ()
{
	Shape *circle = new Circle;

	RedShapeDecorator *redCircle = new RedShapeDecorator(new Circle);

	cout<<"Basic Functionality"<<endl;
	circle->draw();

	cout<<"Decorator Functionality"<<endl;
	redCircle->draw();

	delete redCircle;
	delete circle;
}


