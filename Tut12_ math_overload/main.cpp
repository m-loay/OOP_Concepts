/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>
#include "TimeBase.h"
using namespace std;

int main()
{
	Time_Base t(0,0,0);
	Time_Base t1(1,1,1);

	cout << "\n\nTesting Adding exp:\n";
	t=t+t1;
	cout << " t is "<< t<<endl;


	cout << "\n\nTesting the prefix increment operator:\n"
		 << " t is "<< t << endl;
	cout << "++t is "<< ++t << endl;
	cout << " t is "<< t<<endl;

	cout << "\n\nTesting the postfix increment operator:\n"
		 << " t is "<< t << endl;
	cout << "t++ is "<< t++ << endl;
	cout << " t is "<< t<<endl;


	cout << "\n\nTesting Adding value:\n"
		 << " t is "<< t << endl;
	cout << "t+3 is "<< t+3 << endl;
	cout << " t is "<< t<<endl;



}
