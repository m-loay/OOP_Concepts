/*
 * ChainPattern.h
 *
 *  Created on: Oct 26, 2016
 *      Author: modys
 */

#ifndef CHAINPATTERN_H_
#define CHAINPATTERN_H_

#include"Logger.h"

using namespace std;

class ChainPattern
{
public:
	ChainPattern()
	{
		cout<<"ChainPattern is Called"<<endl;
	}
	~ChainPattern()
	{
		cout<<"~ChainPattern is Called"<<endl;
	}

	static Logger* getChainofLogger()
	{
		Logger* errorLogger = new ErrorLogger(Logger::ERROR);
		Logger* fileLogger = new FileLogger(Logger::FILE);
		Logger* consoleLogger = new ConsoleLogger(Logger::CONSOLE);

		errorLogger->setNextLogger(fileLogger);
		fileLogger->setNextLogger(consoleLogger);

		return errorLogger;
	}
};


#endif /* CHAINPATTERN_H_ */
