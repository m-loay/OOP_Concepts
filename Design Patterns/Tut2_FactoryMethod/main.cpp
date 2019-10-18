/*
 * main.cpp<<
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#include <iostream>
#include <vector>

#include "../Tut2_FactoryMethod/Shape.h"
using namespace std;

int main()
{

	/*Create vector of pointers to class shape*/
	vector<Shape*>shapes;

	/*Create a pointer to class ShapeFactory*/
	ShapeFactory *sfact = new ShapeFactory;
	int choice;

	/*Create a loop to save a base pointers(shape) to desired derived objects*/
	while(true)
	{
		cout << "Circle(1) Square(2) Rectangle(3) Go(0): "<<endl;
		cin >> choice;
		if (choice == 0)
			break;
		shapes.push_back(sfact->getShape(choice));
	}

	/*Draw the deisred derived objects*/
	for (unsigned int i = 0; i < shapes.size(); i++)
		shapes[i]->draw();

	/*Free all allocation*/
	for (unsigned int i = 0; i < shapes.size(); i++)
		delete shapes[i];
	delete sfact;
}

