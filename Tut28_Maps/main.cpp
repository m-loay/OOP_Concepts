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

typedef map<string, string> MapString;
int main ()
{
	MapString family;
	family.insert(MapString::value_type("Father","x"));
	family.insert(MapString::value_type("Mother","y"));
	family.insert(MapString::value_type("Son","Mody"));
	family.insert(MapString::value_type("F.Daughter","z"));
	family.insert(MapString::value_type("S.Daughter","s"));
	family.insert(MapString::value_type("S.Daughter","s"));
	family.insert(MapString::value_type("S.Daughter","s"));

	for(MapString::const_iterator it = family.begin(); it != family.end(); ++it)
	{
		cout<<it->first<<" is "<<it->second<<endl;
	}
}

