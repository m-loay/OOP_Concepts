/*
 * Employee.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: modys
 */

#include "Employee.h"
#include <iostream>

using namespace std;
EmployeeNoMemberInitializer::EmployeeNoMemberInitializer(const string &first , const string &last , 
                                                         const Date &db , const Date &hb)
:firstName(first),
 lastName(last)
{
    // TODO Auto-generated constructor stub
    birthDate = db;
    hireDate = hb;
    cout<<"EmployeeNoMemberInitializer constructor"<<firstName<<" "<<lastName<<"called"<<endl;
}

EmployeeNoMemberInitializer::~EmployeeNoMemberInitializer()
{
    // TODO Auto-generated destructor stub
    cout<<"EmployeeNoMemberInitializer Destructor"<<firstName<<" "<<lastName<<"called"<<endl;
}

void EmployeeNoMemberInitializer::print()const
{
    cout<<"Employee "<<firstName<<" "<<lastName<<" was born in"<<endl;
    birthDate.print();
    cout <<"and hired in ";
    hireDate.print();
}

EmployeeWithMemberInitializer::EmployeeWithMemberInitializer(const string &first , const string &last , 
                                                             const Date &db , const Date &hb)
:firstName(first),
 lastName(last),
 birthDate(db),
 hireDate(hb)
{
    // TODO Auto-generated constructor stub
    cout<<"EmployeeWithMemberInitializer constructor"<<firstName<<" "<<lastName<<"called"<<endl;
}

EmployeeWithMemberInitializer::~EmployeeWithMemberInitializer()
{
    // TODO Auto-generated destructor stub
    cout<<"EmployeeWithMemberInitializer destructor "<<firstName<<" "<<lastName<<"called"<<endl;
}

void EmployeeWithMemberInitializer::print()const
{
    cout<<"Employee "<<firstName<<" "<<lastName<<" was born in"<<endl;
    birthDate.print();
    cout <<"and hired in ";
    hireDate.print();
}

EmployeeWithMemberInitializerREF::EmployeeWithMemberInitializerREF(const string &first , const string &last ,
                                                                   const Date &db , const Date &hb)
:firstName(first),
 lastName(last),
 birthDate(db),
 hireDate (hb)
{
    // TODO Auto-generated constructor stub
    cout<<"EmployeeWithMemberInitializerREF constructor "<<firstName<<" "<<lastName<<"called"<<endl;
}

EmployeeWithMemberInitializerREF::~EmployeeWithMemberInitializerREF()
{
    // TODO Auto-generated destructor stub
    cout<<"EmployeeWithMemberInitializerREF destructor "<<firstName<<" "<<lastName<<"called"<<endl;
}

void EmployeeWithMemberInitializerREF::print()const
{
    cout<<"Employee "<<firstName<<" "<<lastName<<" was born in"<<endl;
    birthDate.print();
    cout <<"and hired in ";
    hireDate.print();
}

