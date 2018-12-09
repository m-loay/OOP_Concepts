/*
 * Boiler.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: mloay
 */

#include "Boiler.h"
using namespace std;

Boiler::Boiler()
{
	// TODO Auto-generated constructor stub
	cout<<"Boiler Constructor"<<endl;
}

Boiler::~Boiler()
{
	// TODO Auto-generated destructor stub
	cout<<"Boiler Destructor"<<endl;
}

void Boiler::BoilerMakeCoffee(bool val)
{
		if(val == true)
		{
			setBoiler(true);
			setSafetyValve(false);
		}
		else
		{
			setBoiler(false);
			setSafetyValve(false);
		}
}


bool Boiler::BoilerCanBoil(void)
{
		return true;
}

void Boiler::setBoiler(bool val)
{
	cout<<"setBoiler = "<<val <<endl;
}

void Boiler::setSafetyValve(bool val)
{
	cout<<"setSafetyValve= "<<val<<endl;
}


bool Boiler::getBoiler(void)
{
	return(true);
}
