/*
  * main.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: modys
 */

#include <iostream>
#include <cstring>
//#include <concepts>
#include "maximum.h"
#include "Boxvol.h"
using namespace std;
int var(3);

template <typename T> T maxmum(T a, T b)
{
	return (a > b)? a:b;
}

//template <typename T> const T& maxmum(const T& a, const T& b)
//{
//	return (a > b)? a:b;
//}

template<>
const char* maxmum<const char*>(const char*  a, const char * b)
{
	return (std::strcmp(a,b)>0)?a:b;

}

// syntax 1
// template <typename N>
// requires std::integral<N> || std::floating_point<N>
// N add(N a, N b)
// {
// 	return a+b;
// }


// syntax 2
//template <std::integral N>
//N add(N a, N b)
//{
//	return a+b;
//}

// syntax 3

//auto add(std::integral auto a, std::integral auto b)
//{
//	return a+b;
//}

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
}

