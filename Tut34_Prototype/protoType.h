/*
 * protoType.h
 *
 *  Created on: Oct 23, 2016
 *      Author: modys
 */

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

using namespace std;

class Shape 
{
	public:
		Shape()
		{
			cout<<"Shape constructor called"<<endl;
		}

		virtual ~Shape()
		{
			cout<<"Shape destructor called"<<endl;
		}

		virtual void draw()=0;
		virtual Shape *clone()=0;
};


class Circle : public Shape 
{
	public:
		Circle()
		{
			cout<<"Circle constructor called"<<endl;	
		}

		~Circle()
		{
			cout<<"Circle destructor called"<<endl;
		}

		void draw() { cout << "Circle\n"; }

		Circle *clone(){return new Circle;}
};

class Square : public Shape 
{
	public:
		Square()
		{
			cout<<"Square constructor called"<<endl;	
		}

		~Square()
		{
			cout<<"Square destructor called"<<endl;
		}

		void draw() { cout << "Square\n"; }

		Square *clone(){return new Square ; }
};


class Rectangle : public Shape 
{
	public:
		Rectangle()
		{
			cout<<"Rectangle constructor called"<<endl;	
		}

		~Rectangle()
		{
			cout<<"Rectangle destructor called"<<endl;
		}

		void draw() { cout << "Rectangle\n"; }

		Rectangle *clone(){return new Rectangle ; }
};

class Prototype
{
	public:
		Prototype()
		{
			cout<<"Prototype constructor called"<<endl;
		}
		virtual ~Prototype()
		{
			cout<<"Prototype destructor called"<<endl;
		}
		static Shape *getPrototype(int choice);

	private:
		static Shape* s_prototypes[4];
};

Shape *Prototype::getPrototype(int choice)
{
	return s_prototypes[choice]->clone();
}

Shape *Prototype::s_prototypes[]=
{
		new Circle ,new Square , new Rectangle 
};



#endif /* PROTOTYPE_H_ */
