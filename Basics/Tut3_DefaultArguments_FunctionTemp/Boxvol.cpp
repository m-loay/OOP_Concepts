/*
 * Boxvol.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: modys
 */

#include "Boxvol.h"

Box_vol::Box_vol()
{
	// TODO Auto-generated constructor stub
	setDim(1,1,1);
}

Box_vol::~Box_vol() {
	// TODO Auto-generated destructor stub
}

void Box_vol:: setDim(int length, int width, int height)
{
	len=length;
	wid=width;
	high=height;
}

int Box_vol:: getVolume(void)
{
	return len * wid * high;
}

void Box_vol:: print_volume (void)
{
	cout<<"volume= "<<getVolume()<<endl;
}

void Box_vol:: max_valueInt(int op1, int op2, int op3)
{
	biggest_int=maximum(op1, op2, op3);
}

int Box_vol:: getBiggestInt(void)
{
	return biggest_int;
}

void Box_vol:: max_valueDouble(double op1, double op2, double op3)
{
	biggest_double=maximum(op1, op2, op3);
}

double Box_vol:: getBiggestDouble(void)
{
	return biggest_double;
}

