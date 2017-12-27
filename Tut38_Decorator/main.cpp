/*
 * main.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: modys
 */
#include "ShapeDecorator.h"

int main ()
{
	/*Creating two objects normal object and decorated object*/
	Shape *circle = new Circle;
	RedShapeDecorator *redCircle = new RedShapeDecorator(new Circle);

	/*See the functionality of both normal object or decorated object*/
	cout<<"Basic Functionality"<<endl;
	circle->draw();

	cout<<"Decorator Functionality"<<endl;
	redCircle->draw();

	/*Free Allocation*/
	delete redCircle;
	delete circle;
}


