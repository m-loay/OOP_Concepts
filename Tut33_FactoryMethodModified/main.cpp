/*
 * main.cpp<<
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#include <iostream>
#include <vector>
#include "Widget.h"
#include "OsFactory.h"

using namespace std;

int main()
{

	Factory *windows = OsFactory::getOsComponents(2);

	windows ->create_button();
	windows->create_menu();

	//delete osfactory;
	delete windows;

	cout<<endl;

}

