/*
 * main.cpp
 *
 *  Created on: Sep 29, 2016
 *      Author: modys
 */

#include <iostream>
#include <map>
#include <iterator>
using namespace std;
typedef map<int, double> MapInt;

void printMap (const map<int, double> &Map );

int main ()
{
	MapInt pairs;

	/*Insert eight value type object in pairs*/
	pairs.insert(MapInt::value_type(1 ,1.1));
	pairs.insert(MapInt::value_type(2 ,2.2));
	pairs.insert(MapInt::value_type(3 ,3.3));
	pairs.insert(MapInt::value_type(4 ,4.4));
	pairs.insert(MapInt::value_type(5 ,5.5));
	pairs.insert(MapInt::value_type(3 ,6.6)); //dup value
	pairs.insert(MapInt::value_type(7 ,7.7)); 
	pairs.insert(MapInt::value_type(1 ,8.8)); //dup value

	/*print the map content*/
	cout<<"pairs contains: \nKeys\tValue"<<endl;
	printMap(pairs);

	/*Change the map content*/
	pairs[1] = 10.10;
	pairs[5] = 50.50;

	/*print the map content*/
	cout<<"pairs contains: \nKeys\tValue"<<endl;
	printMap(pairs);
}

void printMap (const map<int, double> &Map)
{
	typename map<int, double>::const_iterator const_it;

	for(const_it = Map.begin() ; const_it != Map.end() ; const_it++)
	{
		cout<<const_it->first << '\t' << const_it->second <<endl;
	}
}