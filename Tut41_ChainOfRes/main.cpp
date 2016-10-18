/*
 * main.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#include"ChainBase.h"
#include<ctime>

int main()
{
	srand(time(0));
	Handler1 root;
	Handler2 two;
	Handler3 thr;
	root.add(&two);
	root.add(&thr);
	thr.setNext(&root);
	for (int i = 1; i < 10; i++)
	{
		root.handle(i);
		cout << '\n';
	}
}


