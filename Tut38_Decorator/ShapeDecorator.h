/*
 * ShapeDecorator.h
 *
 *  Created on: Oct 24, 2016
 *      Author: modys
 */

#ifndef SHAPEDECORATOR_H_
#define SHAPEDECORATOR_H_
#include "Shape.h"

class ShapeDecorator
{
public:
	ShapeDecorator(Shape *sh):shapeDec(sh)
	{
		cout<<"ShapeDecorator called"<<endl;
	}

	virtual ~ShapeDecorator()
	{
		cout<<"~ShapeDecorator called"<<endl;
	}

	virtual void draw()=0;

protected:
	Shape *shapeDec;
};

class RedShapeDecorator :public ShapeDecorator
{
public:
	RedShapeDecorator(Shape *sh):ShapeDecorator(sh)
	{
		cout<<"RedShapeDecorator called"<<endl;
	}

	virtual ~RedShapeDecorator()
	{
		cout<<"~RedShapeDecorator called"<<endl;
	}

	void draw()
	{
		shapeDec->draw();
		setBorder(shapeDec);
	}

private:
	void setBorder(Shape *sh)
	{
		cout<<"setBorder red"<<endl;
	}
};

#endif /* SHAPEDECORATOR_H_ */
