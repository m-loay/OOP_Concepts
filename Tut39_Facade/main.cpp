/*
 * main.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#include <iostream>
#include <string>
using namespace std;


// Subsystem 1
class SubSystemOne
{
public:
	SubSystemOne()
	{
		cout<<"SubSystemone called"<<endl;
	}

	~SubSystemOne()
	{
		cout<<"~SubSystemone called"<<endl;
	}
	void MethodOne(){ cout << "SubSystem 1" << std::endl; };
};

// Subsystem 2
class SubSystemTwo
{
public:
	SubSystemTwo()
	{
		cout<<"SubSystemTwo called"<<endl;
	}

	~SubSystemTwo()
	{
		cout<<"~SubSystemTwo called"<<endl;
	}
	void MethodTwo(){ cout << "SubSystem 2" << std::endl; };
};

// Subsystem 3
class SubSystemThree
{
public:
	SubSystemThree()
	{
		cout<<"SubSystemThree called"<<endl;
	}

	~SubSystemThree()
	{
		cout<<"~SubSystemThree called"<<endl;
	}
	void MethodThree(){ cout << "SubSystem 3" << std::endl; }
};


// Facade
class Facade
{
public:
    Facade()
    {
		pOne = new SubSystemOne();
		pTwo = new SubSystemTwo();
		pThree = new SubSystemThree();
		cout<<"Facade called"<<endl;
    }

    ~Facade()
    {
		cout<<"~Facade called"<<endl;
		delete pOne;
		delete pTwo;
		delete pThree;
    }

    void MethodA()
    {
		cout << "Facade::MethodA" << std::endl;
		pOne->MethodOne();
		pTwo->MethodTwo();
    }

    void MethodB()
    {
		cout << "Facade::MethodB" << std::endl;
		pTwo->MethodTwo();
		pThree->MethodThree();
    }

private:
    SubSystemOne *pOne;
    SubSystemTwo *pTwo;
    SubSystemThree *pThree;
};

int main()
{
    Facade *pFacade = new Facade();

    pFacade->MethodA();
    pFacade->MethodB();

    delete pFacade;

    return 0;
}
