/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: modys
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

typedef set< double, less<double> > doubleSet;
template <typename T>
void printSet (const set<T>&Set);


int main ()
{
	const int size = 6;
	bool dups =0;
	double a[size]={1.1,2.2,3.3,4.4,5.5,3.3};
	doubleSet fnum (a,a+size);
	pair <doubleSet::const_iterator,bool> p;
	cout<<"Size of Fnum =  "<<fnum.size()<<endl;
	cout<<"Fnum data"<<endl;
	printSet(fnum);

	cout << "insert element \"6.6\"" << endl;
	p = fnum.insert(6.6);
	cout<<"element "<<*(p.first)<<(p.second?" was ":" was not ")<<"inserted"<<endl;
	printSet(fnum);

	cout << "insert element \"6.6 as duplicate\"" << endl;
	p = fnum.insert(6.6);
	cout<<"element "<<*(p.first)<<(p.second?" was ":" was not ")<<"inserted"<<endl;
	printSet(fnum);

	cout << "Search 4.4" << endl;
	doubleSet::const_iterator it = fnum.find(4.4);
	cout<<"element"<<(it != fnum.end()?" was":" was not")<<" found"<<endl;
	printSet(fnum);

	cout<<"Find duplicate element in an array"<<endl;
	doubleSet fnumber;
	for(int i=0; i<size; i++)
	{
		p = fnumber.insert(a[i]);
		if(p.second == false)
		{
			dups = 1;
			break;
		}
	}
	cout<<"Array "<<(dups?" has ":" has not ")<<"Duplicates elements"<<endl;

}

template <typename T>
void printSet (const set<T>&Set)
{
	typename set<T>::const_iterator constIterator;
	for(constIterator = Set.begin(); constIterator!=Set.end();++constIterator)
	{
		cout<<*constIterator<<" ";
	}
	cout<<endl;
}


