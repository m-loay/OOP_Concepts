/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>
class Car
{
	public:
	/*init() is not a constructor, 
	  it can be called during the normal program flow, 
	  where member variables may already be set and 
	  dynamically allocated memory may already be allocated. */
	void init()
	{
		std::cout<<"Init function"<<std::endl;
		fuel_ = 40;
		passenger_ = 3;
	}
	Car()
	{
		init();
		speed_ = 0;
		std::cout<<"Car()"<<std::endl;
	}

	Car(int speed)
	{
		init();
		speed_ = speed;
		std::cout<<"Car(int speed)"<<std::endl;
	}

	void dasbord()const
	{
		std::cout<<"car Dash Board"<<std::endl;
		std::cout<<"Fuel in car = "<<fuel_<<std::endl;
		std::cout<<"Passengers in car = "<<passenger_<<std::endl;
		std::cout<<"speed of car = "<<speed_<<std::endl;
	}

	private:
	int fuel_{0};
	int passenger_{0};
	float speed_{0.0f};
};

class Vehicle
{
	public:
	Vehicle()
	{
		std::cout<<"Vehicle()"<<std::endl;
	}

	Vehicle(int speed):Vehicle()
	{
		speed_ = speed;
		std::cout<<"Vehicle(int speed)"<<std::endl;
	}

    Vehicle(int speed, int fuel):Vehicle(speed)
    {
        fuel_ = fuel;
        std::cout<<"Vehicle(int speed, int fuel)"<<std::endl;
    }

	void dasbord()const
	{
		std::cout<<"Vehicle Dash Board"<<std::endl;
		std::cout<<"Fuel in Vehicle = "<<fuel_<<std::endl;
		std::cout<<"Passengers in Vehicle = "<<passenger_<<std::endl;
		std::cout<<"speed of Vehicle = "<<speed_<<std::endl;
	}

	private:
	int fuel_{40};
	int passenger_{3};
	float speed_{0.0f};
};

int main()
{
	std::cout<<"\n -----Use default constructor-----"<<std::endl;
	//create object from both classes
	Car c;
	Vehicle v;

	//view dash board
	c.dasbord();
	v.dasbord();
	

	std::cout<<"\n -----Use paramertrized constructor-----"<<std::endl;
	Car c2(5);
	Vehicle v2(5);

	//view dash board
	c2.dasbord();
	v2.dasbord();

    Vehicle c3(10,20);
    c3.dasbord();
}
