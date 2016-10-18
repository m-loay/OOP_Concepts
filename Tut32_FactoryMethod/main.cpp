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
		cout << "LinuxButton(1) LinuxMenu(2) WindowsButton(3) WindowsMenu(4) Go(0): "<<endl;
		cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(Widget::make_Widget(choice));
	}

	for (unsigned int i = 0; i < roles.size(); i++)
		roles[i]->draw();

	for (unsigned int i = 0; i < roles.size(); i++)
		delete roles[i];

}

