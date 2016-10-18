/*
 * main.cpp<<
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#include <iostream>
#include <vector>
#include "Widget.h"
using namespace std;

int main()
{
	vector<Widget*>roles;
	int choice;
	while(true)
	{
		cout << "LinuxButton(0) LinuxMenu(1) WindowsButton(2) WindowsMenu(3) Go(4): "<<endl;
		cin >> choice;
		if (choice == 4)
			break;
		roles.push_back(Factory::make_Widget(choice));
	}

	for (unsigned int i = 0; i < roles.size(); i++)
		roles[i]->draw();

	for (unsigned int i = 0; i < roles.size(); i++)
		delete roles[i];
}

