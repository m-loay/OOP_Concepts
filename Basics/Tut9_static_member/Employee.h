/*
 * Employee.h
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include<string>
using namespace std;

class Employee {
public:
    Employee(const string &, const string &  );
    ~Employee();
    string getFirstName()const;
    string getFLastName()const;
    static int getCount();

private:
    string firstName;
    string lastName;
    static int count;
};

#endif /* EMPLOYEE_H_ */
