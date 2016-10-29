/*
 * IAppliance.h
 *
 *  Created on: Oct 24, 2016
 *      Author: modys
 */

#ifndef IAPPLIANCE_H_
#define IAPPLIANCE_H_

#include <iostream>
using namespace std;
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

#endif /* IAPPLIANCE_H_ */
