/*
 * FlyWeight.h
 *
 *  Created on: Oct 25, 2016
 *      Author: modys
 */

#ifndef FLYWEIGHT_H_
#define FLYWEIGHT_H_

#include <map>
#include <algorithm>
#include <iterator>

#include "../Tut9_Flyweight/Shape.h"

typedef map<string, Circle *> MapString;

class FlyWeight
{
public:
	FlyWeight()
	{
		cout<<"FlyWeight called"<<endl;
	}

	~FlyWeight()
	{
		cout<<"~FlyWeight called"<<endl;
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

MapString FlyWeight::circleObj;

#endif /* FLYWEIGHT_H_ */
