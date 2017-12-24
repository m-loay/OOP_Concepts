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
       virtual void on()=0;
       virtual void off()=0;
};

class SonyTV : public IAppliance
{
private:
        std::string name;
public:
        SonyTV(std::string _name)
        {
            name = _name;
            cout<<"SonyTV constructor called"<<endl;
        }

       ~ SonyTV()
        {
            cout<<"SonyTV destructor called"<<endl;
        }

        void on()
        {
            std::cout << name <<"SonyTV is Switched-On" << std::endl;
        }
        void off()
        {
            std::cout << name <<"SonyTV is Switched-Off" << std::endl;
        }
     };

class SamsungTV : public IAppliance
    {
private:
        std::string name;

public:
        SamsungTV(std::string _name)
        {
            name = _name;
            cout<<"SamsungTV constructor called"<<endl;
        }

        ~SamsungTV()
        {
        	  cout<<"SamsungTV destructor called"<<endl;
        }
        void on()
        {
            std::cout << name <<"SamsungTV is Switched-On" << std::endl;
        }
        void off()
        {
            std::cout << name <<"SamsungTV is Switched-Off" << std::endl;
        }
    };

#endif /* IAPPLIANCE_H_ */
