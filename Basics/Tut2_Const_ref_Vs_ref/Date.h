/*
 * Date.h
 *
 *  Created on: Sep 22, 2016
 *      Author: modys
 */



#ifndef DATE_H_
#define DATE_H_
#include <iostream>
using namespace std;

class Date
{
public:
    static const int monthPerYear = 12;
    Date(int =1, int = 1, int = 1900 ,int =1);
    virtual ~Date();
    void setDay(int);
    int getDay()const;
    void print () const;

private:
    int month_;
    int year_;
    int day_;
    int ID_;
};

#endif /* DATE_H_ */
