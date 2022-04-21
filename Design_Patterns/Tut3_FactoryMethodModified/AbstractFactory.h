/*
 * OsFactory.h
 *
 *  Created on: Oct 23, 2016
 *      Author: modys
 */
/*
 * AbstractFactory.h
 *
 *  Created on: Oct 23, 2016
 *      Author: modys
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_
#include "../Tut3_FactoryMethodModified/Colour.h"
#include "shape.h"
using namespace std;

/**
 * Abstract factory defines methods to create all
 * related products.
 */

class AbstractFactory
{
	public:
		AbstractFactory()
		{
			cout<<"AbstractFactory constructor called"<<endl;
		}
		virtual ~AbstractFactory()
		{
			cout<<"AbstractFactory destructor called"<<endl;
		}
		virtual Shape *getShape(int choice)=0;
		virtual Colour *getColour(int choice)=0;
};

class ShapeFactory : public AbstractFactory
{
	public:
		ShapeFactory()
		{
			cout<<"ShapeFactory constructor called"<<endl;	
		}

		~ShapeFactory()
		{
			cout<<"ShapeFactory destructor called"<<endl;
		}

		 Shape *getShape(int choice)
		 {
			switch (choice)
			{
			case 1:
				return new Circle;
				break;

			case 2:
				return new Square;
				break;

			case 3:
				return new Rectangle;
				break;

			default:
				return NULL;
				break;
			}			 
		 }

		 Colour *getColour(int choice){return NULL;}
};
	

class ColourFactory : public AbstractFactory
{
	public:

		ColourFactory()
		{
			cout<<"ColourFactory constructor called"<<endl;	
		}

		~ColourFactory()
		{
			cout<<"ColourFactory destructor called"<<endl;
		}

		Shape *getShape(int choice){return NULL;}
		Colour *getColour(int choice)
		{
			switch (choice)
			{
				case 1:
					return new Red;
					break;

				case 2:
					return new Green;
					break;

				case 3:
					return new Blue;
					break;

				default:
					return NULL;
					break;
			}
		}
};


class FactoryProducer
{
	public:

	FactoryProducer()
	{
			cout<<"FactoryProducer called"<<endl;
	}
	virtual ~FactoryProducer()
	{
		cout<<"~FactoryProducer called"<<endl;
	}

	static AbstractFactory *getFactory(int choice)
	{
		switch (choice)
		{
		case 1:
			return new ShapeFactory;
			break;

		case 2:
			return new ColourFactory;
			break;

		default:
			return 0;
			break;
		}
	}
};


#endif /* ABSTRACTFACTORY_H_ */
