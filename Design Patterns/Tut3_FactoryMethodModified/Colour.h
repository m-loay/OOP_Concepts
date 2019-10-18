/*
 * COLOUR.h
 *
 *  Created on: Oct 15, 2016
 *      Author: modys
 */

#ifndef COLOUR_H_
#define COLOUR_H_
#include <iostream>
using namespace std;

class Colour 
{
	public:
		Colour()
		{
			cout<<"Colour constructor called"<<endl;
		}

		virtual ~Colour()
		{
			cout<<"Colour destructor called"<<endl;
		}

		virtual void fill()=0;
};


class Red : public Colour 
{
	public:
		Red()
		{
			cout<<"Red constructor called"<<endl;	
		}

		~Red()
		{
			cout<<"Red destructor called"<<endl;
		}
		void fill() { cout << "Fill it with Red\n"; }
};

class Green : public Colour 
{
	public:
		Green()
		{
			cout<<"Green constructor called"<<endl;	
		}

		~Green()
		{
			cout<<"Green destructor called"<<endl;
		}
		void fill() { cout << "Fill it with Green\n"; }
};


class Blue : public Colour 
{
	public:
		Blue()
		{
			cout<<"Blue constructor called"<<endl;	
		}

		~Blue()
		{
			cout<<"Blue destructor called"<<endl;
		}
		void fill() { cout << "Fill it with Blue\n"; }
};

#endif /* COLOUR_H_ */
