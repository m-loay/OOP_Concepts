/*
 * Facade.h
 *
 *  Created on: Oct 24, 2016
 *      Author: modys
 */

#ifndef FACADE_H_
#define FACADE_H_
#include "../Tut8_Facade/Shape.h"

class Facade
{
public:
	Facade()
	{
		cout<<"Facade called"<<endl;
		circle = new Circle;
		rectangle = new Rectangle;
		square = new Square;
	}

	virtual ~Facade()
	{
		cout<<"~Facade called"<<endl;
		delete circle;
		delete rectangle;
		delete square;
	}

	void drawCircle()
	{
		circle->draw();
	}

	void drawRectangle()
	{
		rectangle->draw();
	}

	void drawSquare()
	{
		square->draw();
	}

private:
	Shape *circle;
	Shape *rectangle;
	Shape *square;
};

#endif /* FACADE_H_ */
