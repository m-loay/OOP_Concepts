#include "Integer.h"
#include <iostream>
Integer::Integer() 
{
	m_pInt = new int(0);
	std::cout << "Integer() -->" << *m_pInt <<std::endl;
}

Integer::Integer(int value) 
{
	m_pInt = new int(value);
	std::cout << "Integer(int)-->" << *m_pInt << std::endl;
}

Integer::Integer(const Integer & obj) 
{
	m_pInt = new int(*obj.m_pInt);
	std::cout << "Integer(const Integer&)-->" << *m_pInt << std::endl;
}

Integer::Integer(Integer && obj) 
{
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
	std::cout << "Integer(int&&)-->" << *m_pInt << std::endl;
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
	std::cout << "~Integer" << std::endl;
	delete m_pInt;
}

std::ostream & operator<<(std::ostream & out, const Integer & obj)
{
	out << *obj.m_pInt;
	return out;
}






