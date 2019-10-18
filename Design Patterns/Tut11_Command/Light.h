/*
 * Light.h
 *
 *  Created on: Oct 26, 2016
 *      Author: modys
 */

#ifndef LIGHT_H_
#define LIGHT_H_
#include<iostream>
using namespace std ;

// Receiver Class
class Light
{
public:
	Light()
	{
		cout<<"Light is called"<<endl;
	}
	virtual ~Light()
	{
		cout<<"~Light is called"<<endl;
	}

	void on()
	{
		cout << "The light is on\n";
	}
	void off()
	{
		cout << "The light is off\n";
	}
};
#endif /* LIGHT_H_ */
