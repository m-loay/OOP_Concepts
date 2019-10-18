/*
 * Array.h
 *
 *  Created on: Jun 20, 2016
 *      Author: modys
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include<iostream>
using namespace std;

class Array
{
	friend ostream &operator<<( ostream &, const Array & );
	friend istream &operator>>( istream &, Array & );

public:

	Array(int=10);// default constructor
	Array(const Array &);// copy constructor
	~Array();// default destructor

	// equality operator overload
	bool operator==(const Array &)const;

	// inequality operator; returns opposite of == operator using operator overload
	bool operator!=(const Array &right)const
	{
		return !(*this==right);// invokes Array::operator==
	}

	// prefix operator overload
	const Array &operator++();

	// postfix operator overload
	const Array operator++(int);

	//Assignment operator
	const Array &operator=(const Array&); // assignment operator

	//Add two objects using overload
	const Array& operator+(const Array& left);

	// return size
	int getSize()const;

	//return the counter value
	int getCounter()const;

	// subscript operator for non-const objects returns modifiable lvalue
	int &operator[](int);

	// subscript operator for const objects returns rvalue
	int operator[](int)const;

private:
	int size;// pointer-based array size
	int *ptr;// pointer to first element of pointer-based array
	int counter;

};

#endif /* ARRAY_H_ */
