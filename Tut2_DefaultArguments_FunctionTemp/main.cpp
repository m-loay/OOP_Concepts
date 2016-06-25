/*
  * main.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: modys
 */

#include <iostream>
#include "maximum.h"
#include "Boxvol.h"
using namespace std;


int main ()
{

	Box_vol volume_box;
	volume_box.print_volume();

	/*Default Arguments*/
	volume_box.setDim();
	volume_box.print_volume();

	volume_box.setDim(10);
	volume_box.print_volume();

	volume_box.setDim(10,5);
	volume_box.print_volume();

	volume_box.setDim(10,5,2);
	volume_box.print_volume();

	/*Function Template*/
	volume_box.max_valueInt(10,5,2);
	cout << "dBiggest int: "<<volume_box.getBiggestInt() <<endl;// prompt user for data

	volume_box.max_valueDouble(10.5,5.3,2.1);
	cout << "dBiggest double: "<<volume_box.getBiggestDouble() <<endl;// prompt user for data

}

