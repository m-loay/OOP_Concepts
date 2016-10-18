/*
 * main.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: modys
 */

#include <iostream>
#include "GlobalClassS.h"
#include "Singleton.h"
using namespace std;

// Default initialization
GlobalClassS *global_ptr = 0;
Singleton *Singleton::s_instance = 0;

GlobalClassS obj2;
void foo (void)
{
	if (!global_ptr)
		global_ptr = new GlobalClassS;
	global_ptr->setValue(1,1);
	cout << "foo: global_ptr is " << global_ptr->getValue() << '\n';
}

void foo2(void)
{
	Singleton::instance()->setValue(1);
	cout << "foo2: global_ptr is " << Singleton::instance()->getValue() << '\n';
}

void bar(void)
{
	if (!global_ptr)
		global_ptr = new GlobalClassS;
	global_ptr->setValue(2,2);
	cout << "bar: global_ptr is " << global_ptr->getValue() << '\n';
}

void bar2(void)
{
	Singleton::instance()->setValue(2);
	cout << "foo2: global_ptr is " << Singleton::instance()->getValue() << '\n';
}

int main()
{
	if (!global_ptr)
		global_ptr = new GlobalClassS;
	cout << "main: global_ptr is " << global_ptr->getValue() << '\n';
	foo();
	bar();
	foo2();
	bar2();
}
