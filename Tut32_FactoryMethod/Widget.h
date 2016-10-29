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
	virtual void draw()=0;
	virtual ~Widget()
	{
		cout<<"Widget destructor called"<<endl;
	}
	static Widget *make_Widget(int choice);
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
};

class widgetFactory
{
public:
	widgetFactory()
	{
		cout<<"widgetFactory constructor called"<<endl;
	}

	~widgetFactory()
	{
		cout<<"widgetFactory destructor called"<<endl;
	}

	static Widget *make_Widget(int choice);


};

Widget *widgetFactory::make_Widget(int choice)
{
	switch (choice)
	{
	case 1:
		return new LinuxButton;
		break;

	case 2:
		return new LinuxMenu;
		break;

	case 3:
		return new WindowsButton;
		break;

	case 4:
		return new WindowsMenu;
		break;

	default:
		return 0;
		break;
	}
}


#endif /* WIDGET_H_ */
