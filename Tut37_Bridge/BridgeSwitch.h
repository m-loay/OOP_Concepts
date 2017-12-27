/*
 * BridgeSwitch.h
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#ifndef BRIDGESWITCH_H_
#define BRIDGESWITCH_H_

#include <iostream>
#include "IAppliance.h"
using namespace std;

class Switch
{
public:
	Switch()
	{
		cout<<"Switch constructor called"<<endl;
	}
	virtual ~Switch()
	{
		cout<<"Switch destructor called"<<endl;
	}
	virtual void turnOn()=0;
	virtual void turnOff()=0;
};


class BridgeSwitch : public Switch
{

public:
    BridgeSwitch(IAppliance* backend)
    {
        iAppliance = backend;
        cout<<"BridgeSwitch constructor called"<<endl;
    }

    ~BridgeSwitch()
    {
    	cout<<" BridgeSwitch destructor called"<<endl;
    }

    void turnOn()
    {
        cout << "Using Bridge";
        iAppliance->on();
    }
    
    void turnOff()
    {
        cout << "Using Bridge";
        iAppliance->off();
    }

private:
    IAppliance* iAppliance;
};

class RemoteControl : public Switch
{

public:
        RemoteControl(IAppliance* i)
        {
        	iAppliance = i;
        	cout<<"RemoteControl constructor called"<<endl;
        }

        ~RemoteControl()
        {
        	cout<<"RemoteControl destructor called"<<endl;
        }

        void turnOn()
        {
            cout << "Using Remote ";
            iAppliance->on();
        }

        void turnOff()
        {
            cout << "Using Remote ";
            iAppliance->off();
        }
private:
    IAppliance* iAppliance;
};

class Normal : public Switch
{
public:
		Normal(IAppliance* i)
		{
			iAppliance = i;
			cout<<"Normal constructor called"<<endl;
		}

		~Normal()
		{
			cout<<"Normal destructor called"<<endl;
		}

        void turnOn()
        {
            cout << "Using Normal  ";
            iAppliance->on();
        }

        void turnOff()
        {
            cout << "Using Normal  ";
            iAppliance->off();
        }

private:
    IAppliance* iAppliance;

};

#endif /* BRIDGESWITCH_H_ */
