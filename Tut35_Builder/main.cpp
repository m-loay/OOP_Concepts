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
    Car* nissanCar; // Final product
    Car* jeepCar; // Final product

    /* A builder who controls the process */
    CarBuilder carbuilder;

    /* Build a Jeep */
    cout << "Jeep" << std::endl;
    jeepCar = carbuilder.getJeepCar(); // using JeepBuilder instance
    jeepCar->specifications();

    std::cout << std::endl;

    /* Build a Nissan */
    cout << "Nissan" << std::endl;
    nissanCar = carbuilder.getNissanCar(); // using JeepBuilder instance
    nissanCar->specifications();

    delete nissanCar;
    delete jeepCar;

    return 0;
}


