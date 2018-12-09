/*
 * Boiler.h
 *
 *  Created on: Sep 19, 2018
 *      Author: mloay
 */

#ifndef BOILER_H_
#define BOILER_H_
#include <iostream>
class Boiler {
public:
	Boiler();
	virtual ~Boiler();
	/*start/stop the coffee*/
	void BoilerMakeCoffee(bool val);

	bool BoilerCanBoil(void);
private:
	/*Set heater element to work*/
	void setBoiler(bool val);

	/*Set safety to work*/
	void setSafetyValve(bool val);

	/*Check if there is water in the boiler*/
	bool getBoiler(void);
};

#endif /* BOILER_H_ */
