/*
 * ChainBase.h
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#ifndef CHAINBASE_H_
#define CHAINBASE_H_
#include<iostream>
#include<cstdlib>
using namespace std;
class ChainBase
{
public:
	ChainBase():next(0)
	{
		cout<<"ChainBase is called"<<endl;
	}
	virtual ~ChainBase()
	{
		cout<<"~ChainBase is called"<<endl;
	}
	void setNext(ChainBase *n)
	{
		next = n;
	}
	void add(ChainBase *n)
	{
		if (next)
			next->add(n);
		else
			next = n;
	}
	// 2. The "chain" method in the base class always delegates to the next obj
	virtual void handle(int i)
	{
		next->handle(i);
	}

private:
	ChainBase *next; // 1. "next" pointer in the base class
};

class Handler1: public ChainBase
{
  public:
	Handler1()
	{
		cout<<"Handler1 is called"<<endl;
	}
	virtual ~Handler1()
	{
		cout<<"~Handler1 is called"<<endl;
	}
     void handle(int i)
    {
        if (rand() % 3)
        {
            // 3. Don't handle requests 3 times out of 4
            cout << "H1 passed " << i << "  "<<endl;
            ChainBase::handle(i); // 3. Delegate to the base class
        }
        else
          cout << "H1 handled " << i << "  "<<endl;
    }
};

class Handler2: public ChainBase
{
  public:
	Handler2()
	{
		cout<<"Handler2 is called"<<endl;
	}
	virtual ~Handler2()
	{
		cout<<"~Handler2 is called"<<endl;
	}
    void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H2 passed " << i << "  "<<endl;
            ChainBase::handle(i);
        }
        else
          cout << "H2 handled " << i << "  "<<endl;
    }
};

class Handler3: public ChainBase
{
  public:
	Handler3()
	{
		cout<<"Handler3 is called"<<endl;
	}
	virtual ~Handler3()
	{
		cout<<"~Handler3 is called"<<endl;
	}
    void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H3 passed " << i << "  "<<endl;
            ChainBase::handle(i);
        }
        else
          cout << "H3 handled " << i << "  "<<endl;
    }
};


#endif /* CHAINBASE_H_ */
