/*
 * main.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#include <iostream>
#include "builder.h"
#include <string.h>
using namespace std;

int main()
{
    Car* car; // Final product

    /* A director who controls the process */
    Director director;

    /* Concrete builders */
    JeepBuilder jeepBuilder;
    NissanBuilder nissanBuilder;

    /* Build a Jeep */
    std::cout << "Jeep" << std::endl;
    director.setBuilder(&jeepBuilder); // using JeepBuilder instance
    car = director.getCar();
    car->specifications();

    std::cout << std::endl;

    /* Build a Nissan */
    std::cout << "Nissan" << std::endl;
    director.setBuilder(&nissanBuilder); // using NissanBuilder instance
    car = director.getCar();
    car->specifications();
    delete car;

    return 0;
}


