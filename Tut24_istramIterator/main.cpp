/*
 * main.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: modys
 */
#include <iostream>
#include <iterator>
using namespace std;
int main ()
{
	cout<<"Enter two integers"<<endl;
	istream_iterator<int> inputInt(cin);
	int number1 = *inputInt;
	inputInt++;
	int number2 = *inputInt;

	ostream_iterator<int>outoutInt(cout);
	cout<<"The sum is ";
	outoutInt = number1+number2;
	cout<<endl;

}



