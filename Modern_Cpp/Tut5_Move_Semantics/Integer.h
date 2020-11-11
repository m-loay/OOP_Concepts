#ifndef INTEGER_H_
#define INTEGER_H_

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

	//Assignment operator
	Integer &operator=(const Integer&);

	//overload + assignemet
	Integer operator+(const Integer&);

	//overload pre-increment ++ assignemet
	Integer &operator++();

	//overload post-increment ++ assignemet
	Integer operator++(int);

	//setter & getter
	int GetValue()const;
	void SetValue(int value);
	~Integer();

};

#endif /* EMPLOYEE_H_ */