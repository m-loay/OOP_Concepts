/*
 * Logger.h
 *
 *  Created on: Oct 26, 2016
 *      Author: modys
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include<iostream>
#include <string>

using namespace std;

class Logger
{

public:
	Logger():level(0),pLogger(0)
	{
		cout<<"Logger is Called"<<endl;
	}
	virtual ~Logger()
	{
		cout<<"~Logger is Called"<<endl;
	}

	static int CONSOLE ;
	static int ERROR;
	static int FILE;

	void setNextLogger (Logger *ptrLogger)
	{
		pLogger = ptrLogger;
	}

	void logMessage(int _level , string msg)
	{
		if (level == _level)
		{
			write(msg);
		}

		if(pLogger != 0)
		{
			pLogger->logMessage(_level , msg);
		}
	}

protected:
	int level;
	Logger *pLogger;
	virtual void write(string msg)=0;
};

int Logger ::CONSOLE =1;
int Logger::ERROR =3;
int Logger::FILE =2;

class ConsoleLogger :public Logger
{
public:
	ConsoleLogger(int _level)
	{
		level = _level;
		cout<<"ConsoleLogger is Called"<<endl;
	}
	~ConsoleLogger()
	{
		cout<<"~ConsoleLogger is Called"<<endl;
	}

protected:
	void write(string msg)
	{
		cout<<" Standard Console::Logger: " <<msg<<endl;
	}

};

class ErrorLogger  :public Logger
{
public:
	ErrorLogger (int _level)
	{
		level = _level;
		cout<<"ErrorLogger  is Called"<<endl;
	}
	~ErrorLogger ()
	{
		cout<<"~ErrorLogger  is Called"<<endl;
	}

protected:
	void write(string msg)
	{
		cout<<" Error Console::Logger: " <<msg<<endl;
	}

};

class FileLogger   :public Logger
{
public:
	FileLogger  (int _level)
	{
		level = _level;
		cout<<"FileLogger   is Called"<<endl;
	}
	~FileLogger  ()
	{
		cout<<"~FileLogger   is Called"<<endl;
	}

protected:
	void write(string msg)
	{
		cout<<" FileLogger Console::Logger: " <<msg<<endl;
	}

};

#endif /* LOGGER_H_ */
