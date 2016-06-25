/*
 * PhoneNumber.h
 *
 *  Created on: Jun 19, 2016
 *      Author: modys
 */

#ifndef PHONENUMBER_H_
#define PHONENUMBER_H_

#include<iostream>
#include<string>
using namespace std;

class PhoneNumber {
public:
	PhoneNumber();
	~PhoneNumber();
	friend ostream &operator<<( ostream &, const PhoneNumber & );
	friend istream &operator>>( istream &, PhoneNumber & );

private:
	string firstName; // 3-digit area code
	string lastName; // 3-digit exchange
};

#endif /* PHONENUMBER_H_ */
