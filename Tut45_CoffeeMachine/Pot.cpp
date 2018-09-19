/*
 * Pot.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: mloay
 */

#include "Pot.h"
using namespace std;

Pot::Pot()
{
	// TODO Auto-generated constructor stub
	cout<<"Pot Constructor"<<endl;

}

Pot::~Pot()
{
	// TODO Auto-generated destructor stub
	cout<<"Pot Destructor"<<endl;
}

void Pot::PotWarmeCoffee(void)
{
	if(PotIsfull())
	{
		setWarmer(true);
	}
	else
	{
		setWarmer(false);
	}
}

bool Pot::PotCanReceive(void)
{
	if(getPlate() !=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pot::PotIsfull(void)
{
	if(getPlate() ==3)
	{
		return true;
	}
	else
	{
		return false;
	}
}



