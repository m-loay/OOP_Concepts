/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include<iostream>
#include "Date.h"
using namespace std;

void passObjectByValue (Date x);
void passObjectByRef (Date &x);
void passObjectByConstRef (const Date &x);

int main()
{
    /*Create an object and print it*/
    Date d1(7,1,1990,1);

    d1.print();

    /*Send object by value requires calling the default copy constructor.*/
    passObjectByValue(d1);
    cout<<"Printing the object after modification pass by value  "<<endl;
    d1.print();

    /*Send object by reference will not require calling the copy constructor  
    and it allows modifying the object.*/
    passObjectByRef(d1);
    cout<<"Printing the object after modification pass by reference  "<<endl;
    d1.print();

    /*Send the object by constant reference , will disallow modifying the object.*/
    passObjectByConstRef(d1);
    cout<<"Printing the object after call pass by constant reference  "<<endl;
    d1.print();

}

void passObjectByValue (Date x)
{
    cout<<"Execute passObjectByValue  "<<endl;
    cout<<"day = "<<x.getDay()<<endl;
    cout<<"Modify the object inside the function to 10  "<<endl;
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
