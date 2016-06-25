/*
 * PhoneNumber.cpp
 *
 *  Created on: Jun 19, 2016
 *      Author: modys
 */
#include<iostream>
using namespace std;
#include "PhoneNumber.h"
#include<iomanip>
PhoneNumber::PhoneNumber()
{
	// TODO Auto-generated constructor stub
	cout<<"Constructore is Called"<<endl;

}

PhoneNumber::~PhoneNumber()
{
	// TODO Auto-generated destructor stub
	cout<<"Destructor is called"<<endl;
}

ostream &operator<< (ostream &output, const PhoneNumber &number)
{
	output << number.firstName<<" "<<number.lastName;
	return output;
}

istream &operator>>( istream &input, PhoneNumber &number )
{

	input >> setw( 5) >> number.firstName; // input area code
	input >> setw( 4) >> number.lastName;// input exchange

	return input; // enables cin >> a >> b >> c;
}
