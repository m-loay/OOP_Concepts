/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>
class Car
{
	public:
	Car()
	{
		std::cout<<"Car()"<<std::endl;
	}

	Car(int amount)
	{
		fuel_ = amount;
		std::cout<<"Car(int amount)"<<std::endl;
	}

	Car(int amount , int pass)
	{
		fuel_ = amount;
		passenger_ = pass;
		std::cout<<"Car(int amount , int pass)"<<std::endl;
	}

	void dasbord()const
	{
		std::cout<<"car Dash Board"<<std::endl;
		std::cout<<"Fuel in car = "<<fuel_<<std::endl;
		std::cout<<"Passengers in car = "<<passenger_<<std::endl;
		std::cout<<"speed of car = "<<passenger_<<std::endl;
	}

	private:
	int fuel_{0};
	int passenger_{0};
	float speed_{0.0f};
};

class Vehicle
{
	public:
	Vehicle():Vehicle(0)
	{
		std::cout<<"Vehicle()"<<std::endl;
	}

	Vehicle(int amount):Vehicle(amount,0)
	{
		fuel_ = amount;
		std::cout<<"Vehicle(int amount)"<<std::endl;
	}
	
	Vehicle(int amount , int pass)
	{
		fuel_ = amount;
		passenger_ = pass;
		std::cout<<"Vehicle(int amount , int pass)"<<std::endl;
	}

	void dasbord()const
	{
		std::cout<<"Vehicle Dash Board"<<std::endl;
		std::cout<<"Fuel in Vehicle = "<<fuel_<<std::endl;
		std::cout<<"Passengers in Vehicle = "<<passenger_<<std::endl;
		std::cout<<"speed of Vehicle = "<<passenger_<<std::endl;
	}

	private:
	int fuel_{0};
	int passenger_{0};
	float speed_{0.0f};
};

int main()
{
	//create object from both classes
	Car c;
	Vehicle v;

	//view dash board
	c.dasbord();
	v.dasbord();
}
