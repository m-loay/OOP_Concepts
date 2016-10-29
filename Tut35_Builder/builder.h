/*
 * builder.h
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#ifndef BUILDER_H_
#define BUILDER_H_
#include<iostream>
using namespace std;


/***** Car parts *****/
class Wheel
{
public:
	Wheel()
	{
		cout<<"Wheel Constructor Called"<<endl;
		size = 0;
	}

	~Wheel()
	{
		cout<<"Wheel Destructor Called"<<endl;
	}
	int size;
};

class Engine
{
public:
	Engine()
	{
		cout<<"Engine Constructor Called"<<endl;
		horsepower = 0;
	}

	~Engine()
	{
		cout<<"Engine Destructor Called"<<endl;
	}
	int horsepower;
};

class Body
{
public:
	Body()
	{
		cout<<"Body Constructor Called"<<endl;
	}

	~Body()
	{
		cout<<"Body Destructor Called"<<endl;
	}
	string shape;
};

/****** Final product -- a car ******/
class Car
{
public:
	Car()
	:engine(0),body(0)
	{
		cout<<"Car Constructor Called"<<endl;
		wheelsFrontLeft = new Wheel;
		wheelsRearLeft = new Wheel;
		wheelsFrontRight = new Wheel;
		wheelsRearRight = new Wheel;
		engine = new Engine;
		body = new Body;
	}

	~Car()
	{
		cout<<"Car Destructor Called"<<endl;
		delete wheelsFrontLeft;
		delete wheelsRearLeft;
		delete wheelsFrontRight;
		delete wheelsRearRight;
		delete engine;
		delete body;
	}
	Wheel*   wheelsFrontLeft;
	Wheel*   wheelsRearLeft;
	Wheel*   wheelsFrontRight;
	Wheel*   wheelsRearRight;
	Engine*  engine;
	Body* body;

	void specifications()
	{
		cout << "body:" << body->shape << std::endl;
		cout << "engine horsepower:" << engine->horsepower << std::endl;
		cout << "tire size:" << wheelsFrontLeft->size << "'" << std::endl;
	}
};

/***** Builder is responsible for constructing the smaller parts *******/

class CarBuilder
{

public:
	CarBuilder()
	{
		cout<<"CarBuilder Constructor Called"<<endl;
	}

	~CarBuilder()
	{
		cout<<"CarBuilder Destructor Called"<<endl;
	}

	static Car* getNissanCar()
	{
		Car* car = new Car();

		car->body->shape="hatch back";

		car->engine->horsepower = 85;

		car->wheelsFrontLeft->size = 16;
		car->wheelsRearLeft->size = 16;
		car->wheelsFrontRight->size = 16;
		car->wheelsRearRight->size = 16;

		return car;
	}

	static Car* getJeepCar()
	{
		Car* car = new Car();

		car->body->shape = "SUV";

		car->engine->horsepower = 400;

		car->wheelsFrontLeft->size = 22;
		car->wheelsRearLeft->size = 22;
		car->wheelsFrontRight->size = 22;
		car->wheelsRearRight->size = 22;

		return car;
	}
};




#endif /* BUILDER_H_ */
