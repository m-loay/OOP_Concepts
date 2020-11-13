#pragma once
#include <iostream>
class Integer 
{
public:
	//Default constructor
	Integer();

	//Parameterized constructor
	Integer(int value);

	//Copy constructor
	Integer(const Integer &obj);

	//Move constructor
	Integer(Integer &&obj);

	//overload = assignemet
	Integer &operator=(const Integer &);

	//overload = assignemet Move Constructor
	Integer &operator=(Integer &&);

	//overload + assignemet
	Integer operator+(const Integer &)const;

	//overload pre-increment ++ assignemet
	Integer &operator++();

	//overload post-increment ++ assignemet
	Integer operator++(int);

	//overload == assignemet
	bool operator==(const Integer &)const;

	//int operator overload
	operator int ();

	//setter & getter
	int GetValue()const;
	std::string GetName()const;
	void SetValue(int value);
	~Integer();

private:
	int *m_pInt;
	static int counter;
	std::string name;
	void assignName();

};
