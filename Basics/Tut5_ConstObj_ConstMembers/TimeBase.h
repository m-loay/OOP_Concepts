/*
 * TimeBase.h
 *
 *  Created on: Jun 14, 2016
 *      Author: modys
 */

#ifndef TIMEBASE_H_
#define TIMEBASE_H_

#include "iostream"
using namespace std;

class Time_Base
{
public:
    Time_Base(int= 0, int= 0,int= 0);
    ~Time_Base();

    void setTime (int , int , int );
    void setHour (int  );
    void setMin (int );
    void setSec (int );

    int getHour () const;
    int getMin () const;
    int getSec() const;

    void printUniversal()const;
    void printStandard ();

private:
    int hour;
    int minute;
    int second;
};

#endif /* TIMEBASE_H_ */
