/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include <iostream>
#include "TimeBase.h"

using namespace std;

int main ()
{
	Time_Base wakeUp(6,45,0); // non-constant object
	const Time_Base noon(12,0,0); // constant object


														// OBJECT 			MEMBER FUNCT
	wakeUp.setHour(18); 								// non-const 		non-const		True
//	noon.setHour(12); 									// const 			non-const		ERROR
	cout<<"get wake_up"<<wakeUp.getHour();  			// non-const 		const			True
	noon.getMin();  									// const 			const			True
	noon.printUniversal();								// const 			const			True
//	noon.printStandard(); 								// const 			non-const		ERRoR

}
