/*
 * CoffeeMachines.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: mloay
 */

#include "CoffeeMachines.h"
using namespace std;
CoffeeMachines::CoffeeMachines(const Boiler &ref_boil , const Pot &ref_pot)
{
	// TODO Auto-generated constructor stub
	cout<<"CoffeeMachines Constructor"<<endl;
	this->ref_boil = ref_boil;
	this->ref_pot = ref_pot;
	prev_state = false;
	state = true;
}

CoffeeMachines::~CoffeeMachines()
{
	// TODO Auto-generated destructor stub
	cout<<"CoffeeMachines destructor"<<endl;
}

void CoffeeMachines::coffeMachineUpdate(void)
{
	if(getButton() == true)
	{
		if(prev_state == false)
		{
			// opening
			prev_state = true;
			setLight(true);
			if(ref_boil.BoilerCanBoil() && ref_pot.PotCanReceive())
			{
				ref_boil.BoilerMakeCoffee(true);
			}
			else
			{
				ref_boil.BoilerMakeCoffee(false);
			}
		}
		else
		{
			// closing
			prev_state = false;
			setLight(false);
			setSafetyValve(true);
		}
	}
	else
	{
		/*do nothing*/
	}
	ref_pot.PotWarmeCoffee();
}
