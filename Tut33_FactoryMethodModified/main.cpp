/*
 * main.cpp<<
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#include <iostream>
#include <vector>
#include "Colour.h"
#include "Shape.h"
#include "AbstractFactory.h"

using namespace std;

int main()
{
	/*Create vector of pointers to class shape*/
	vector<Shape*>shapes;
	vector<Colour*>colours;

	/*Create a pointer from avstract factory*/
	AbstractFactory *shapeColurType = NULL;

	/*Selection paramters*/
	int shapeType;
	int colourType; 

		/*Create a loop to save a base pointers(shape) to desired derived objects*/
	while(true)
	{
		/*Creating object from Factory according to user desire*/
		cout << "Circle(1) Square(2) Rectangle(3) Go(0): "<<endl;
		cin >> shapeType;

		cout << "Red(1) Green(2) Blue(3) Go(0): "<<endl;
		cin >> colourType;
		if (shapeType == 0 || colourType==0)
			break;
		shapeColurType = FactoryProducer::getFactory(1);
		shapes.push_back(shapeColurType->getShape(shapeType));

		shapeColurType = FactoryProducer::getFactory(2);
		colours.push_back(shapeColurType->getColour(colourType));
	}

	for(unsigned int i = 0; i<shapes.size();i++)
	{
		/*Printing Data of each object*/
		shapes[i]->draw();
		colours[i]->fill();
	}

	/*Free all allocation*/
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
		delete colours[i];	
	}
	delete shapeColurType;
}
