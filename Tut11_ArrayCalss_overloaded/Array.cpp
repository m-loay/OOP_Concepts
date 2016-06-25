/*
 * Array.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: modys
 */

#include "Array.h"
#include<iostream>
#include<iomanip>
#include<cstdlib> // exit function prototype
using namespace std;

Array::Array(int arraySize)
{
	// TODO Auto-generated constructor stub
	size=(arraySize>0 ?arraySize:10);
	ptr=new int [size];

	for (int var = 0; var < size; var++)
	{
		ptr[var]=0;
	}
	cout<<"Constructor is Called"<<endl;
}

Array::Array(const Array &arrayTocopy)
//:size(arrayTocopy.size)
{
	size=arrayTocopy.size;
	ptr=new int [size];
	for (int var = 0; var < size; var++)
	{
		ptr[var]=arrayTocopy.ptr[var];
	}
	cout<<"Copy Constructor is Called"<<endl;
}


Array::~Array()
{
	// TODO Auto-generated destructor stub
	delete[] ptr; // release pointer-based array space
	cout<<"Destructor is Called"<<endl;
}

int Array::getSize()const
{
	return size;
}

const  Array &Array:: operator =(const Array &right)
{
	if( &right != this)
	{
		// for Arrays of different sizes, deallocate original
		// left-side array, then allocate new left-side array
		if( size != right.size )
		{
			delete[] ptr; // release space
			size = right.size; // resize this object
		}
		ptr = new int[ size ]; // create space for array copy

		for( int i = 0; i < size; i++ )
			ptr[ i ] = right.ptr[ i ]; // copy array into object
	} // end outer if

	return *this; // enables x = y = z, for example
}// end function operator=

bool Array:: operator==(const Array &right)const
						{
	if(size!=right.size)
		return false;

	for (int var = 0; var < size; var++)
	{
		if(ptr[var]!=right.ptr[var])
			return false;
	}
	return true;
						}

int &Array::operator[](int sub)
{
	if(sub<0|| sub>size)
	{
		cerr<<"Error Sub"<<sub<<"out of range"<<endl;
		exit(1);
	}
	return ptr[sub];
}

int Array::operator[](int sub)const
{
	if(sub<0|| sub>size)
	{
		cerr<<"Error Sub"<<sub<<"out of range"<<endl;
		exit(1);
	}
	return ptr[sub];
}

ostream &operator<<(ostream &output , const Array &a )
{
	int i;

	// output private ptr-based array
	for(i=0;i<a.size;i++)
	{
		output << setw( 12) << a.ptr[ i ];

		if( ( i + 1) % 4== 0) // 4 numbers per row of output
			output << endl;
	}// end for

	if( i % 4!= 0) // end last line of output
		output << endl;

	return output; // enables cout << x << y;
}

istream &operator>>(istream &input , Array &a)
{
	for( int i = 0; i < a.size; i++ )
		input >> a.ptr[ i ];
	return input; // enables cin >> x >> y;
}
