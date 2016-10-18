/*
 * Decorator.h
 *
 *  Created on: Oct 17, 2016
 *      Author: modys
 */

#ifndef DECORATOR_H_
#define DECORATOR_H_
#include <iostream>
using namespace std;
#include <string>
#include <iostream>
using namespace std;

class AbstractNPC
{
public:
	AbstractNPC()
	{
		cout<<"AbstractNPC called"<<endl;
	}

	virtual ~AbstractNPC()
	{
		cout<<"~AbstractNPC called"<<endl;
	}
	virtual void draw() = 0;
};

class NPC: public AbstractNPC
{
private:
	int height;
	int width;
public:
	NPC(int h , int w)
	{
		height = h;
		width = w;
		cout<<"NPC called"<<endl;
	}

	virtual ~NPC()
	{
		cout<<"~NPC called"<<endl;
	}
	void draw()
	{
		cout << "height = "<<height<<"  width ="<<width <<endl;
	}
};

class NPCDecorator: public AbstractNPC
{
private:
	AbstractNPC * npc;
public:
	NPCDecorator(AbstractNPC *n)
	{
		npc = n;
		cout<<"NPCDecorator called"<<endl;
	}

	virtual ~NPCDecorator()
	{
		cout<<"~NPCDecorator called"<<endl;
	}

	void draw()
	{
		npc->draw();
	} // delegate render to npc data member
};

class Elite: public NPCDecorator {
public:
	Elite(AbstractNPC *n): NPCDecorator(n)
	{
		cout<<"Elite called"<<endl;
	}

	virtual ~Elite()
	{
		cout<<"~Elite called"<<endl;
	}
	void draw()
	{
		cout << "Elite "; // render special features
		NPCDecorator::draw(); // delegate to base class
	}
};

class Captain: public NPCDecorator {
public:
	Captain(AbstractNPC *n): NPCDecorator(n)
	{
		cout<<"Captain called"<<endl;
	}

	virtual ~Captain()
	{
		cout<<"~Captain called"<<endl;
	}

	void draw()
	{
		cout << "Captain "; // render special features
		NPCDecorator::draw(); // delegate to base class
	}
};

class Shaman: public NPCDecorator {
public:
	Shaman(AbstractNPC *n): NPCDecorator(n)
	{
		cout<<"Shaman called"<<endl;
	}

	virtual ~Shaman()
	{
		cout<<"~Shaman called"<<endl;
	}

	void draw() {
		NPCDecorator::draw(); // delegate to base class
		cout << " Shaman "; // render special features *after* base
	}
};

#endif /* DECORATOR_H_ */
