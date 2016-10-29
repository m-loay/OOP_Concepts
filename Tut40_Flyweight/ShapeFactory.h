/*
 * ShapeFactory.h
 *
 *  Created on: Oct 25, 2016
 *      Author: modys
 */

#ifndef SHAPEFACTORY_H_
#define SHAPEFACTORY_H_

#include"Shape.h"
#include <map>
#include <algorithm>
#include <iterator>

typedef map<string, Circle *> MapString;

class ShapeFactory
{
public:
	ShapeFactory()
	{
		cout<<"ShapeFactory called"<<endl;
	}

	~ShapeFactory()
	{
		cout<<"~ShapeFactory called"<<endl;
	}

	static Circle*getCircle(string cl)
	{
		static MapString::const_iterator it;
		it = circleObj.find(cl);

		if(it == circleObj.end())
		{
			Circle *c = new Circle(cl);
			circleObj.insert(MapString::value_type(cl,c));
			cout<<"Creating circle of color : "<<cl<<endl;
			return c;
		}

		return (it->second);
	}

private:
	static MapString circleObj;
};

MapString ShapeFactory::circleObj;

#endif /* SHAPEFACTORY_H_ */
