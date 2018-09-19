/*
 * CoffeeMachines.h
 *
 *  Created on: Sep 19, 2018
 *      Author: mloay
 */

#ifndef COFFEEMACHINES_H_
#define COFFEEMACHINES_H_
#include<iostream>
#include"Pot.h"
#include"Boiler.h"
class CoffeeMachines {
public:
	CoffeeMachines(const Boiler &ref_boil , const Pot &ref_pot);
	virtual ~CoffeeMachines();
	void coffeMachineUpdate();

private:
	Boiler &ref_boil;
	Pot &ref_pot;
	bool prev_state;
	bool state;


	/*Set the light valve to work*/
	void setLight(bool val);

	bool getButton(void);
};

#endif /* COFFEEMACHINES_H_ */
