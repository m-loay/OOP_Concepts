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
	/*Create objects*/
	Time_Base t(0,0,0);
	Time_Base t1(1,1,1);

	/*Testing Adding exp*/
	cout << "\n\nTesting Adding exp:\n";
	t=t+t1;
	cout << " t is "<< t<<endl;


	/*Testing the prefix increment operator*/
	cout << "\n\nTesting the prefix increment operator:\n"
		 << " t is "<< t << endl;
	cout << "++t is "<< ++t << endl;
	cout << " t is "<< t<<endl;

	/*Testing the postfix increment operator*/
	cout << "\n\nTesting the postfix increment operator:\n"
		 << " t is "<< t << endl;
	cout << "t++ is "<< t++ << endl;
	cout << " t is "<< t<<endl;


	/*Testing Adding value*/
	cout << "\n\nTesting Adding value:\n"
		 << " t is "<< t << endl;
	cout << "t+3 is "<< t+3 << endl;
	cout << " t is "<< t<<endl;



}
