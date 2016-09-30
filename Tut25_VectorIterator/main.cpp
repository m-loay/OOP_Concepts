/*
 * main.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: modys
 */


#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <utility>

using namespace std;

template <typename T>
void printVector (const vector<T>&vec);

template <typename T>
void printVectorReverse (const vector<T>&vec);

int main ()
{
	vector<int>integers;

	ostream_iterator< int >output( cout, " " );
	cout<<"Intgers size = "<<integers.size()<<endl;
	cout<<"Intgers Capacity = "<<integers.capacity()<<endl;

	cout<<"Entering data to vector"<<endl;
	integers.push_back(1);
	integers.push_back(2);
	integers.push_back(3);

	cout<<"Intgers size = "<<integers.size()<<endl;
	cout<<"Intgers Capacity = "<<integers.capacity()<<endl;
	printVector(integers);

	integers.pop_back();
	printVector(integers);

	integers.push_back(3);
	integers.push_back(4);
	integers.push_back(5);
	printVectorReverse(integers);

	cout<<"use Copy"<<endl;
	copy(integers.begin(),integers.end(),output);

	integers[0]=10;
	cout<<"integers[0]=10"<<endl;
	printVector(integers);

	integers.insert(integers.begin()+1,22);
	cout<<"integers.insert(integers.begin()+1,22)"<<endl;
	printVector(integers);

	integers.erase(integers.begin());
	cout<<"integers.erase(integers.begin())"<<endl;
	printVector(integers);


}

template <typename T>
void printVector (const vector<T>&vec)
{
	typename vector<T>::const_iterator constIterator;
	for(constIterator = vec.begin(); constIterator!=vec.end();++constIterator)
	{
		cout<<*constIterator<<" ";
	}
	cout<<endl;
}

template <typename T>
void printVectorReverse (const vector<T>&vec)
{
	typename vector<T>::const_reverse_iterator consIterator;
	for(consIterator = vec.rbegin(); consIterator!=vec.rend();++consIterator)
	{
		cout<<*consIterator<<" ";
	}
	cout<<endl;
}



