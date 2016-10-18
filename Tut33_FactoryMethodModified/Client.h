/*
 * Client.h
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Widget.h"

class Client
{
private:
	Factory *factory;

public:
	Client(Factory *f)
	{
		factory = f;
		cout<<"Client constructor called"<<endl;
	}

	virtual ~Client()
	{
		cout<<"Client destructor called"<<endl;
	}

	void draw()
	{
		Widget *w[] =
		{
				factory->create_button(),
				factory->create_menu()
		};
		w[0]->draw();
		w[1]->draw();
	}

};


#endif /* CLIENT_H_ */
