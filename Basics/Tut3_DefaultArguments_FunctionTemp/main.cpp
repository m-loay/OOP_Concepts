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
int var(3);

int main ()
{

	Box_vol volume_box;
	volume_box.print_volume();

	/*Default Arguments*/

	/*Default Arguments, set without using any input arguments*/
	volume_box.setDim();
	volume_box.print_volume();

	/*Default Arguments, set the first arguments only*/
	volume_box.setDim(10);
	volume_box.print_volume();

	/*Default Arguments , set the first and second arguments*/
	volume_box.setDim(10,5);
	volume_box.print_volume();

	/*Default Arguments ,  set all arguments*/
	volume_box.setDim(10,5,2);
	volume_box.print_volume();

	/*Function Template*/

	/*given to function integers arguments*/
	volume_box.max_valueInt(10,5,2);
	cout << "dBiggest int: "<<volume_box.getBiggestInt() <<endl;// prompt user for data

	/*given to function floats arguments*/
	volume_box.max_valueDouble(10.5,5.3,2.1);
	cout << "dBiggest double: "<<volume_box.getBiggestDouble() <<endl;// prompt user for data

	/*compare between local and global scope*/
	{
		int var(6);
		std::cout<<"Printing var in local scope, var = "<<var<<std::endl;

		std::cout<<"Printing var in global scope ::var= "<<::var<<std::endl;
	}

}

