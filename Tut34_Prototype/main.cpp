/*
 * main.cpp<<
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#include <iostream>
#include <vector>
#include "protoType.h"
using namespace std;

int main()
{
	/*Create vector of pointers to class shape*/
	vector<Shape*>roles;

	/*Selection paramters*/
	int choice;

	/*Create a loop to save a base pointers(shape) to desired derived objects*/
	while(true)
	{
		cout << "Circle(0) Square(1) Rectangle(2) Go(3): "<<endl;
		cin >> choice;
		if (choice == 3)
			break;
		roles.push_back(Prototype::getPrototype(choice));
	}

	for (unsigned int i = 0; i < roles.size(); i++)
		roles[i]->draw();

	/*Free all allocation*/
	for (unsigned int i = 0; i < roles.size(); i++)
		delete roles[i];
}

