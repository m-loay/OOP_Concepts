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

/**
 * Abstract factory defines methods to create all
 * related products.
 */
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
	virtual Widget *create_button() = 0;
	virtual Widget *create_menu() = 0;
};

/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 */
class LinuxFactory : public Factory
{
public:
	LinuxFactory()
	{
		cout<<"LinuxFactory constructor called"<<endl;
	}
	virtual ~LinuxFactory()
	{
		cout<<"LinuxFactory destructor called"<<endl;
	}
	Widget *create_button()
	{
		return new LinuxButton;
	}
	Widget *create_menu()
	{
		return new LinuxMenu;
	}
};

/**
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 */
class WindowsFactory : public Factory
{
public:
	WindowsFactory()
	{
		cout<<"WindowsFactory constructor called"<<endl;
	}
	virtual ~WindowsFactory()
	{
		cout<<"WindowsFactory destructor called"<<endl;
	}
	Widget *create_button()
	{
		return new WindowsButton;
	}
	Widget *create_menu()
	{
		return new WindowsMenu;
	}
};


#endif /* WIDGET_H_ */
