/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>
#include <string.h>
int main()
{
    /*Initialization of scalar*/
    int a1 = 0; //Copy initialization
    int a2(5); //Direct initialization
    int a3{}; //Value initialization (will take defult value of standard type 0)
    std::cout<<"===========Scalar types=============="<<std::endl;
    std::cout<<"a1 = "<<a1<<" a2= "<<a2<<" a3= "<<a3<<std::endl;

    /*Initialization of arrays types*/
    char c1[8] = {'\0'};//Copy initialization
    char c2[8] = {"abcd"};//Copy initialization

    char c3[8]{};//Value initialization
    char c4[8]{"Hello"};//Direct initialization
    std::cout<<"===========Array types=============="<<std::endl;
    std::cout<<"c1 = "<<c1<<" c2= "<<c2<<" c3= "<<c3<<" c4= "<<c4<<std::endl;

    /*Initialization of arrays types(Heap Variables*/
    std::cout<<"===========Array types(Heap)=============="<<std::endl;
    int *p1 (new int {});//Value initialization
    int *p2 (new int(5));//Direct initialization
    char *p3 (new char [8]{'a','b'});//Value initialization
    char *p4 (new char [8]{});
    int *p5 (new int[3] {3,2,5});//Value initialization
    strcpy (p4,"copy");
    std::cout<<"*p1 = "<<*p1<<" *p2= "<<*p2<<" *p3= "<<*p3<<" *p4= "<<*p4<<" *p5= "<<*p5<<std::endl;
}
