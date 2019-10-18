/*
 * Shape.h
 *
 *  Created on: Oct 24, 2016
 *      Author: modys
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <string>

using namespace std;

class Shape
{

public:
	Shape()
	{
		cout<<"Shape called"<<endl;
	}

	virtual ~Shape()
	{
		cout<<"~Shape called"<<endl;
	}

	virtual void draw()=0;
};


class Circle :public Shape
{
public:
	Circle(string cl):x(0),y(0),radius(0)
	{
		colour = cl;
		cout<<"Circle called"<<endl;
	}

	virtual ~Circle()
	{
		cout<<"~Circle called"<<endl;
	}

	void draw()
	{
		cout<<"Draw a Circle"<<" colour"<<colour<<" x="<<x<<" y="<<y<<" Radius="<<radius<<endl;
	}

	void setX (int _x)
	{
		x = _x;
	}

	void setY (int _y)
	{
		y = _y;
	}

	void setRadius (int _Radius)
	{
		radius = _Radius;
	}
private:
	int x,y,radius;
	string colour;
};

#endif /* SHAPE_H_ */
