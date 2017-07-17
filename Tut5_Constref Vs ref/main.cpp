/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 *      1)To understand passing object to function mechanisms.
 *      2)Send object by value requires calling the default copy constructor.
 *      3)Send object by reference will not require calling the copy constructor
 *       and it allows modifying the object.
 *      4)Send the object by constant reference , will disallow modifying the object.
 */

#include<iostream>
#include "Date.h"
using namespace std;

void passObjectByValue (Date x);
void passObjectByRef (Date &x);
void passObjectByConstRef (const Date &x);

int main()
{
  Date d1(7,1,1990,1);

  d1.print();

  passObjectByValue(d1);
  cout<<"Printing the object after modification  "<<endl;
  d1.print();

  passObjectByRef(d1);
  cout<<"Printing the object after modification  "<<endl;
  d1.print();

  passObjectByConstRef(d1);
  d1.print();

}

void passObjectByValue (Date x)
{
  cout<<"Execute passObjectByValue  "<<endl;
  cout<<"day = "<<x.getDay()<<endl;
  cout<<"Modify the object inside the function  "<<endl;
  x.setDay(10);
}


void passObjectByRef (Date &x)
{
  cout<<"Execute passObjectByRef  "<<endl;
  cout<<"day = "<<x.getDay()<<endl;
  x.setDay(5);
}

void passObjectByConstRef (const Date &x)
{
  cout<<"Execute passObjectByConstRef  "<<endl;
  cout<<"day = "<<x.getDay()<<endl;
  /*Its not possible to modify the object inside the function*/
  //x.setDay(10);
}
