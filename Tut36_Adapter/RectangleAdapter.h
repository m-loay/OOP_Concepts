/*
 * RectangleAdapter.h
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#ifndef RECTANGLEADAPTER_H_
#define RECTANGLEADAPTER_H_
#include <iostream>
using namespace std;

// Desired interface
class Rectangle
{
  public:
	Rectangle()
	{
		cout<<"Rectangle constructor Called"<<endl;
	}
	virtual ~Rectangle()
	{
		cout<<"Rectangle destructor Called"<<endl;
	}
    virtual void draw() = 0;
};

// Legacy component
class LegacyRectangle
{
  public:

    LegacyRectangle(int x1, int y1, int x2, int y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        cout<<"LegacyRectangle constructor Called"<<endl;
        cout << "LegacyRectangle:  create.  (" << x1_ << "," << y1_ << ") => ("
          << x2_ << "," << y2_ << ")" << endl;
    }

	virtual ~LegacyRectangle()
	{
		cout<<"LegacyRectangle destructor Called"<<endl;
	}

    void oldDraw()
    {
        cout << "LegacyRectangle:  oldDraw.  (" << x1_ << "," << y1_ <<
          ") => (" << x2_ << "," << y2_ << ")" << endl;
    }

  private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
};


class RectangleAdapter:public Rectangle , private LegacyRectangle
{
public:
	RectangleAdapter(int x, int y, int w, int h)
	:LegacyRectangle(x, y, x+w, y+h)
	{
		cout<<"RectangleAdapter constructor Called"<<endl;
        cout << "RectangleAdapter: create.  (" << x << "," << y <<
          "), width = " << w << ", height = " << h << endl;
	}

	virtual ~RectangleAdapter()
	{
		cout<<"RectangleAdapter destructor Called"<<endl;
	}

	virtual void draw()
	{
	     cout << "RectangleAdapter: draw." << endl;
	     oldDraw();
	}
};

#endif /* RECTANGLEADAPTER_H_ */
