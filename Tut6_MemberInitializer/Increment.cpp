/*
 * Increment.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include "Increment.h"

Increment::Increment(int c , int i )
:count(c),
 increment(i)
{
	// TODO Auto-generated constructor stub

}

Increment::~Increment() 
{
	// TODO Auto-generated destructor stub
}

void Increment:: print() const
{
	cout << "count = "<< count << ", increment = "<< increment << endl;
}

void Increment:: addIncrement()
{
	count+=increment;
}
