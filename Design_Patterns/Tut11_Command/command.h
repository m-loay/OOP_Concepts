/*
 * command.h
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>

#include "../Tut11_Command/Light.h"
using namespace std;

class command
{
public:
	command()
	{
		cout<<"command is called"<<endl;
	}
	virtual ~command()
	{
		cout<<"~command is called"<<endl;
	}
	virtual void execute() = 0;
};


// Command for turning on the light
class LightOnCommand : public command
{
public:
        LightOnCommand(Light *light) : mLight(light)
		{
        	cout<<"LightOnCommand is called"<<endl;
        }
        ~LightOnCommand()
		{
        	cout<<"~LightOnCommand is called"<<endl;
        }
		void execute()
		{
			mLight->on();
		}
private:
	Light *mLight;
};

// Command for turning off the light
class LightOffCommand : public command
{
public:
	LightOffCommand(Light *light) : mLight(light)
	{
    	cout<<"LightOffCommand is called"<<endl;
    }
    ~LightOffCommand()
	{
    	cout<<"~LightOffCommand is called"<<endl;
    }
	void execute()
	{
		mLight->off();
	}
private:
	Light *mLight;
};

// Invoker
// Stores the ConcreteCommand object
class RemoteControl
{
public:
	RemoteControl():mCmd(0)
	{
		cout<<"RemoteControl is called"<<endl;
	}
	virtual ~RemoteControl()
	{
		cout<<"~RemoteControl is called"<<endl;
	}
	void setCommand(command *cmd) 
	{
		mCmd = cmd;
	}

	void buttonPressed() 
	{
		mCmd->execute();
	}
private:
	command *mCmd;
};


#endif /* COMMAND_H_ */
