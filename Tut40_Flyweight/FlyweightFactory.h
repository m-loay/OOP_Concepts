/*
 * FlyweightFactory.h
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#ifndef FLYWEIGHTFACTORY_H_
#define FLYWEIGHTFACTORY_H_
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Icon
{
public:
	Icon(char *fileName)
	{
		cout<<"Icon Called"<<endl;
		strcpy(_name, fileName);
		if (!strcmp(fileName, "go"))
		{
			_width = 20;
			_height = 20;
		}
		if (!strcmp(fileName, "stop"))
		{
			_width = 40;
			_height = 40;
		}
		if (!strcmp(fileName, "select"))
		{
			_width = 60;
			_height = 60;
		}
		if (!strcmp(fileName, "undo"))
		{
			_width = 30;
			_height = 30;
		}
	}

	~Icon()
	{
		cout<<"~Icon Called"<<endl;
	}
	const char *getName()
	{
		return _name;
	}
	void draw(int x, int y)
	{
		cout << "   drawing " << _name << ": upper left (" << x << "," << y <<
				") - lower right (" << x + _width << "," << y + _height << ")" <<endl;
	}
private:
	char _name[20];
	int _width;
	int _height;
};

class FlyweightFactory
{
public:
	FlyweightFactory()
	{
		cout<<"FlyweightFactory Called"<<endl;
	}

	virtual ~FlyweightFactory()
	{
		cout<<"~FlyweightFactory Called"<<endl;
	}

	static Icon *getIcon(char name[])
	{
		for (int i = 0; i < _numIcons; i++)
			if (!strcmp(name, _icons[i]->getName()))
				return _icons[i];

		_icons[_numIcons] = new Icon(name);
		return _icons[_numIcons++];
	}
	static void reportTheIcons()
	{
		cout << "Active Flyweights: ";
		for (int i = 0; i < _numIcons; i++)
			cout << _icons[i]->getName() << " ";
		cout << endl;
	}
private:
	enum
	{
		MAX_ICONS = 5
	};
	static int _numIcons;
	static Icon *_icons[MAX_ICONS];
};

int FlyweightFactory::_numIcons = 0;
Icon *FlyweightFactory::_icons[];

class DialogBox
{
  public:
    DialogBox(int x, int y, int incr): _iconsOriginX(x), _iconsOriginY(y),
      _iconsXIncrement(incr)
    {
    	cout<<"DialogBox Called"<<endl;
    }

    virtual ~DialogBox()
	{
		cout<<"~DialogBox Called"<<endl;
	}
    virtual void draw() = 0;
  protected:
    Icon *_icons[3];
    int _iconsOriginX;
    int _iconsOriginY;
    int _iconsXIncrement;
};

class FileSelection: public DialogBox
{
  public:
    FileSelection(Icon *first, Icon *second, Icon *third): DialogBox(100, 100,100)
    {
    	cout<<"FileSelection Called"<<endl;
        _icons[0] = first;
        _icons[1] = second;
        _icons[2] = third;
    }
    virtual ~FileSelection()
	{
		cout<<"~FileSelection Called"<<endl;
	}
    void draw()
    {
        cout << "drawing FileSelection:" << endl;
        for (int i = 0; i < 3; i++)
          _icons[i]->draw(_iconsOriginX + (i *_iconsXIncrement), _iconsOriginY);
    }
};

class CommitTransaction: public DialogBox
{
  public:
    CommitTransaction(Icon *first, Icon *second, Icon *third): DialogBox(150,      150, 150)
    {
    	cout<<"CommitTransaction Called"<<endl;
        _icons[0] = first;
        _icons[1] = second;
        _icons[2] = third;
    }

    virtual ~CommitTransaction()
	{
		cout<<"~CommitTransaction Called"<<endl;
	}

    void draw()
    {
        cout << "drawing CommitTransaction:" << endl;
        for (int i = 0; i < 3; i++)
          _icons[i]->draw(_iconsOriginX + (i *_iconsXIncrement), _iconsOriginY);
    }
};

#endif /* FLYWEIGHTFACTORY_H_ */
