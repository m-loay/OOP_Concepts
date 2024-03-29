/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
 *  The purpose of the tutorial
 *  1)To understand how to calculate the size of object
 *  2)To understand how constructors and destructors are called ,
 *  a
*/

#include<iostream>
#include "TimeBase.h"
using namespace std;

void create (void);

/*Creation of object 1(global)*/
Time_Base t1(1,1,1,1);

int main()
{

    cout << "\nMAIN FUNCTION: EXECUTION BEGINS"<< endl;

    
    cout << "\n Object size depends on data members which are 4 int"<< endl;

    /*Show the size of one element member data*/
    cout<<"The size of one int is -->"<<sizeof(int)<<endl;

    /*Show the size of the object*/
    cout<<"The size of object is -->"<<sizeof(t1)<<endl;

    /*Creation of object 2(local)*/
    Time_Base t2 (2,2,2,2);

    /*Creation of object 3(static local)*/
    static Time_Base t3(3,3,3,3);

    create();

    cout << "\nMAIN FUNCTION: Main resume"<< endl;

    /*Creation of object 4(local)*/
    Time_Base t4 (4,4,4,4);
}

void create (void)
{
    cout << "\ncreate FUNCTION: EXECUTION BEGINS"<< endl;
    /*Creation of object 5(local)*/
    Time_Base t5 (5,5,5,5);
    /*Creation of object 6(static local)*/
    static Time_Base t6(6,6,6,6);
    cout << "\ncreateFUNCTION: EXECUTION ENDS"<< endl;
}
