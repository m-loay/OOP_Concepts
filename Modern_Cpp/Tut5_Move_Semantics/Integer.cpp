#include "Integer.h"
#include <iostream>

//Initialize the provate static member
int Integer::counter = 0;

//Default constructor
Integer::Integer() 
{
	assignName();
	m_pInt = new int(0);
	std::cout << name << " --> Integer()" << std::endl;
}

//Parameterized constructor
Integer::Integer(int value) 
{
	assignName();
	std::cout << name << " --> Integer(int)" << std::endl;
	m_pInt = new int(value);
}

//Copy constructor
Integer::Integer(const Integer & obj) 
{
	assignName();
	std::cout << "Integer(const int&) " << name << " --> from obj " << obj.name <<std::endl;
	m_pInt = new int(*obj.m_pInt);
}

//Move constructor
Integer::Integer(Integer && obj) 
{
	std::cout << "Integer(int&&) " << name << " --> from obj " << obj.name <<std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

//overload = assignemet
const Integer& Integer::operator=(const Integer &rhs)
{
	std::cout << "operator=(const Integer &) " << name << " --> from obj " << rhs.name <<std::endl;
	if(&rhs != this)
	{
		delete m_pInt;
		m_pInt = new int (*rhs.m_pInt);
	}

	return *this;
}

//overload = assignemet Move Constructor
const Integer& Integer::operator=(Integer &&rhs)
{
	std::cout << "operator=(const Integer &&)" << name << " --> from obj " << rhs.name <<std::endl;
	if(&rhs != this)
	{
		delete m_pInt;
		m_pInt = new int (*rhs.m_pInt);
	}
	rhs.m_pInt = nullptr;

	return *this;
}

//overload + assignemet
Integer Integer::operator+(const Integer &rhs)const
{
	std::cout <<"operator+(const Integer &)" << name << " --> from obj " << rhs.name <<std::endl;
	Integer temp;
	*temp.m_pInt = *m_pInt + *rhs.m_pInt;
	return temp;
}

//overload pre-increment ++ assignemet
const Integer& Integer::operator++()
{
	std::cout <<"++operator" << std::endl;
	++(*m_pInt);
	return *this;
}

//overload post-increment ++ assignemet
Integer Integer::operator++(int)
{
	std::cout <<"operator++" << std::endl;
	Integer temp(*this);
	++(*m_pInt);
	return temp;
}

//overload == assignemet
bool Integer:: operator==(const Integer &rhs)const
{
	std::cout <<"operator==" << std::endl;
	return *m_pInt == *rhs.m_pInt;
}

//int operator overload
Integer::operator int ()
{
	std::cout << "operator int" << name<< std::endl;
	return *m_pInt;
}

//setter & getter
int Integer::GetValue() const 
{
	return *m_pInt;
}

std::string Integer::GetName() const 
{
	return name;
}

void Integer::SetValue(int value) 
{
	*m_pInt = value;
}

void Integer:: assignName()
{
    char c = 'a' + counter;
    name = std::string(1, c);
    counter ++;
}

Integer::~Integer() 
{
	std::cout << "~Integer()" << name<< std::endl;
	counter --;
    if(m_pInt != nullptr)
    {
        delete m_pInt;
		
    }
    else
    {
        std::cout << name << "'s value is moved" << std::endl;
    }
}