/*
 * Widget.h
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#ifndef WIDGET_H_
#define WIDGET_H_
#include <iostream>
using namespace std;
class Widget 
{
public:
	Widget()
	{
		cout<<"Widget constructor called"<<endl;
	}
	virtual ~Widget()
	{
		cout<<"Widget destructor called"<<endl;
	}
	virtual void draw()=0;
	virtual Widget * clone()=0;
	static Widget *make_Widget(int choice);
};

class Factory
{
public:
	Factory()
	{
		cout<<"Factory constructor called"<<endl;
	}
	virtual ~Factory()
	{
		cout<<"Factory destructor called"<<endl;
	}
	static Widget *make_Widget(int choice);

private:
	 static Widget* s_prototypes[4];
};

/**
 * Concrete product family 1.
 */
class LinuxButton : public Widget 
{
public:
	LinuxButton()
{
		cout<<"LinuxButton constructor called"<<endl;	
}

	~LinuxButton()
	{
		cout<<"LinuxButton destructor called"<<endl;
	}
	void draw() { cout << "LinuxButton\n"; }
	Widget * clone()
	{
		return new LinuxButton;
	}
};

class LinuxMenu : public Widget 
{
public:
	LinuxMenu()
{
		cout<<"LinuxMenu constructor called"<<endl;	
}

	~LinuxMenu()
	{
		cout<<"LinuxMenu destructor called"<<endl;
	}
	void draw() { cout << "LinuxMenu\n"; }
	Widget * clone()
	{
		return new LinuxMenu;
	}
};

/**
 * Concrete product family 2.
 */
class WindowsButton : public Widget 
{
public:
	WindowsButton()
{
		cout<<"WindowsButton constructor called"<<endl;	
}

	~WindowsButton()
	{
		cout<<"WindowsButton destructor called"<<endl;
	}
	void draw() { cout << "WindowsButton\n"; }
	Widget * clone()
	{
		return new WindowsButton;
	}

};

class WindowsMenu : public Widget 
{
public:
	WindowsMenu()
{
		cout<<"WindowsMenu constructor called"<<endl;	
}

	~WindowsMenu()
	{
		cout<<"WindowsMenu destructor called"<<endl;
	}
	void draw() { cout << "WindowsMenu\n"; }
	Widget * clone()
	{
		return new WindowsMenu;
	}
};


Widget *Factory::make_Widget(int choice)
{
	return s_prototypes[choice]->clone();
}

Widget *Factory::s_prototypes[]=
{
		new LinuxButton ,new LinuxMenu , new WindowsButton , new WindowsMenu
};

#endif /* WIDGET_H_ */
