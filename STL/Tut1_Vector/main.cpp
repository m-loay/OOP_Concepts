/*
 * main.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: modys
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void outputVector (const vector <int>&);
void inputVector (vector<int>&);

int main ()
{
	vector<int>integers1(7);
	vector<int>integers2(10);

	//print sizes of arrays
	cout<<"Integers 1 size"<<integers1.size()<<endl;
	cout<<"Integers 2 size"<<integers2.size()<<endl;

	cout<<"outputs of Integers 1 "<<endl;
	outputVector(integers1);

	cout<<"outputs of Integers 2"<<endl;
	outputVector(integers2);

	//insert data
	cout<<"Enter 7 integers"<<endl;
	inputVector(integers1);

	cout<<"Enter 10 integers"<<endl;
	inputVector(integers2);

	// use inequality (!=) operator with vector objects
	cout << "\nEvaluating: integers1 != integers2" << endl;

	if (integers1 != integers2)
		cout <<"integers 1 and integers 2 are not equal "<<endl;

	// create vector integers3 using integers1 as an
	// initializer; print size and contents
	vector< int >integers3( integers1 ); // copy constructor
	cout<<"output vector 3"<<endl;
	cout<<"Integers 3 size"<<integers3.size()<<endl;
	outputVector(integers3);

	if (integers2 != integers3)
		cout <<"integers 1 and integers 3 are not equal "<<endl;

	integers3 = integers2;
	if (integers2 != integers3)
		cout <<"integers 2 and integers 3 are not equal "<<endl;
	else
		cout << "integers2 and integers3 are equals "<<endl;

	cout<<"output vector 3"<<endl;
	cout<<"Integers 3 size"<<integers3.size()<<endl;
	outputVector(integers3);

}

void outputVector (const vector <int>&array)
{
	size_t i;
	for (i= 0; i < array.size(); ++i)
	{
		cout <<setw(12)<<array[i];
		if ((i+1)% 4 == 0)
		{
			cout<<endl;
		}
	}

	if (i%4 !=0)
		cout <<endl;
}

void inputVector (vector <int>&array)
{
	for(size_t i =0 ; i<array.size();++i)
	{
		cout<<"Enter element "<<i+1<<"/"<<array.size()<<endl;
		cin>>array[i];
	}
}
