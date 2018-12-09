/*
 * Pot.h
 *
 *  Created on: Sep 19, 2018
 *      Author: mloay
 */

#ifndef POT_H_
#define POT_H_
#include <iostream>
class Pot {
public:
	Pot();
	virtual ~Pot();;
	void Pot::PotWarmeCoffee(void);
	bool PotCanReceive(void);
	bool PotIsfull (void);

private:
	void setWarmer(bool val);
	int getPlate( void);
};

#endif /* POT_H_ */
