#include "Integer.h"
#include <iostream>
Integer::Integer() 
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) 
{
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) 
{
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) 
{
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

//overload + assignemet
Integer Integer::operator+(const Integer &rhs)const
{
	Integer temp;
	*temp.m_pInt = *m_pInt + *rhs.m_pInt;
	return temp;
}

//overload pre-increment ++ assignemet
Integer& Integer::operator++()
{
	++(*m_pInt);
	return *this;
}

//overload post-increment ++ assignemet
Integer Integer::operator++(int)
{
	Integer temp(*this);
	++(*m_pInt);
	return temp;
}

//overload == assignemet
bool Integer:: operator==(const Integer &rhs)const
{
	return *m_pInt == *rhs.m_pInt;
}

//overload = assignemet
Integer& Integer::operator=(const Integer &rhs)
{
	if(&rhs != this)
	{
		delete m_pInt;
		m_pInt = new int (*rhs.m_pInt);
	}

	return *this;
}

//int operator overload
Integer::operator int ()
{
	return *m_pInt;
}

int Integer::GetValue() const 
{
	return *m_pInt;
}

void Integer::SetValue(int value) 
{
	*m_pInt = value;
}

Integer::~Integer() 
{
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}