/*
 * main.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#include "RectangleAdapter.h"
int main()
{
	RectangleAdapter *r = new RectangleAdapter(120,200,60,40);
	r->draw();
	delete r;
}


