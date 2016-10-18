/*
 * BridgeSwitch.h
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#ifndef BRIDGESWITCH_H_
#define BRIDGESWITCH_H_
#include <iostream>
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

class IAppliance
{
public:
	IAppliance()
	{
		cout<<"IAppliance constructor called"<<endl;
	}
	virtual ~IAppliance()
	{
		cout<<"IAppliance destructor called"<<endl;
	}
       virtual void run()=0;
       virtual void off()=0;
};

class TV : public IAppliance
{
private:
        std::string name;
public:
        TV(std::string _name)
        {
            name = _name;
            cout<<"TV constructor called"<<endl;
        }

       ~ TV()
        {
            cout<<"TV destructor called"<<endl;
        }

        void run()
        {
            std::cout << name <<" is Switch-On" << std::endl;
        }
        void off()
        {
            std::cout << name <<" is Switch-Off" << std::endl;
        }
     };

class AC : public IAppliance
    {
private:
        std::string name;

public:
        AC(std::string _name)
        {
            name = _name;
            cout<<"AC constructor called"<<endl;
        }

        ~AC()
        {
        	  cout<<"AC destructor called"<<endl;
        }
        void run()
        {
            std::cout << name <<" is Switch-On" << std::endl;
        }
        void off()
        {
            std::cout << name <<" is Switch-Off" << std::endl;
        }
    };


class BridgeSwitch : public Switch
{

protected:
    IAppliance* iAppliance;

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
        std::cout << "Bridge on ";
        iAppliance->run();
    }
    void turnOff()
    {
        std::cout << "Using Bridge";
        iAppliance->off();
    }
};

class RemoteControl : public BridgeSwitch
{

public:
        RemoteControl(IAppliance* i):BridgeSwitch(i)
        {
        	 cout<<"RemoteControl constructor called"<<endl;
        }

        ~RemoteControl()
        {
        	cout<<"RemoteControl destructor called"<<endl;
        }

        void turnOn()
        {
            std::cout << "Using Remote ";
            iAppliance->run();
        }
        void turnOff()
        {
            std::cout << "Using Remote ";
            iAppliance->off();
        }
};

class Normal : public BridgeSwitch
{
public:
        Normal(IAppliance* i):BridgeSwitch(i)
        {
        }

        void turnOn()
        {
            std::cout << "Using Normal  ";
            iAppliance->run();
        }
        void turnOff()
        {
            std::cout << "Using Normal  ";
            iAppliance->off();
        }
};

#endif /* BRIDGESWITCH_H_ */
