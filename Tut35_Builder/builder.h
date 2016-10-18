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
class builder {
public:
	builder();
	virtual ~builder();
};


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
	}

	~Car()
	{
		cout<<"Car Destructor Called"<<endl;
	}
	Wheel*   wheels[4];
	Engine*  engine;
	Body* body;

	void specifications()
	{
		cout << "body:" << body->shape << std::endl;
		cout << "engine horsepower:" << engine->horsepower << std::endl;
		cout << "tire size:" << wheels[0]->size << "'" << std::endl;
	}
};

/***** Builder is responsible for constructing the smaller parts *******/
class Builder
{
public:
	Builder()
	{
		cout<<"Builder Constructor Called"<<endl;
	}

	virtual ~Builder()
	{
		cout<<"Builder Destructor Called"<<endl;
	}
	virtual Wheel* getWheel() = 0;
	virtual Engine* getEngine() = 0;
	virtual Body* getBody() = 0;
};

/*********** Director is responsible for the whole process **************/
class Director
{
	Builder* builder;

public:
	Director()
	:builder(0)
	{
		cout<<"Director Constructor Called"<<endl;
	}

	~Director()
	{
		cout<<"Director Destructor Called"<<endl;
	}
	void setBuilder(Builder* newBuilder)
	{
		builder = newBuilder;
	}

	Car* getCar()
	{
		Car* car = new Car();

		car->body = builder->getBody();

		car->engine = builder->getEngine();

		car->wheels[0] = builder->getWheel();
		car->wheels[1] = builder->getWheel();
		car->wheels[2] = builder->getWheel();
		car->wheels[3] = builder->getWheel();

		return car;
	}
};


/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
public:
	JeepBuilder()
	{
		cout<<"JeepBuilder Constructor Called"<<endl;
	}

	~JeepBuilder()
	{
		cout<<"JeepBuilder Destructor Called"<<endl;
	}
	Wheel* getWheel()
	{
		Wheel* wheel = new Wheel();
		wheel->size = 22;
		return wheel;
	}

	Engine* getEngine()
	{
		Engine* engine = new Engine();
		engine->horsepower = 400;
		return engine;
	}

	Body* getBody()
	{
		Body* body = new Body();
		body->shape = "SUV";
		return body;
	}
};

/* Concrete builder for Nissan family cars */
class NissanBuilder : public Builder
{
public:
	NissanBuilder()
	{
		cout<<"NissanBuilder Constructor Called"<<endl;
	}

	~NissanBuilder()
	{
		cout<<"NissanBuilder Destructor Called"<<endl;
	}
	Wheel* getWheel()
	{
		Wheel* wheel = new Wheel();
		wheel->size = 16;
		return wheel;
	}

	Engine* getEngine()
	{
		Engine* engine = new Engine();
		engine->horsepower = 85;
		return engine;
	}

	Body* getBody()
	{
		Body* body = new Body();
		body->shape = "hatchback";
		return body;
	}
};

#endif /* BUILDER_H_ */
