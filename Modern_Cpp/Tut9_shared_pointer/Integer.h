#pragma once
#include <iostream>
class Integer 
{
	int *m_pInt;
public:
	//Default constructor
	Integer();

	//Parameterized constructor
	Integer(int value);

	//Copy constructor
	Integer(const Integer &obj);

	//Move constructor
	Integer(Integer &&obj);

	//overload + assignemet
	Integer operator+(const Integer &)const;

	//overload ++ assignemet
	Integer &operator++();

	//overload ++ assignemet
	Integer operator++(int);

	//overload == assignemet
	bool operator==(const Integer &)const;

	//overload = assignemet
	Integer &operator=(const Integer &);

	//int operator overload
	operator int ();

	//setter & getter
	int GetValue()const;
	void SetValue(int value);
	~Integer();

};
