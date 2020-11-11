#include "Integer.h"

//default constructor
Integer::Integer() 
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

//Paramertrized constructor
Integer::Integer(int value) 
{
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

//Copy Semanitics constructor
Integer::Integer(const Integer & obj) 
{
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

//Move Semanitics constructor
Integer::Integer(Integer && obj) 
{
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

// //overload + assignemet
// Integer Integer:: operator+ (const Integer & right) 
// {
// 	std::cout << "operator+" << std::endl;
// 	Integer temp;
// 	temp.SetValue(this->GetValue() + right.GetValue());

// 	return temp; // enables x = y = z, for example
// }

// //overload pre-increment ++ assignemet
// Integer& Integer::operator++() 
// {
// 	++(*m_pInt);
// 	return *this;
// }

// //overload post-increment ++ assignemet
// Integer  Integer operator++(int)
// {
// 	Integer temp(*this);
// 	++(*m_pInt);
// 	return temp;
// }

// //overload = assignemet
// Integer& Integer:: operator= (const Integer & right) 
// {
// 	std::cout << "operator=" << std::endl;
// 	if( &right != this)
// 	{
// 		delete m_pInt; // release space
// 		m_pInt = new int(*right.m_pInt); // create space for array copy
// 	} // end outer if

// 	return *this; // enables x = y = z, for example
// }

//getter
int Integer::GetValue() const 
{
	return *m_pInt;
}

//Setter
void Integer::SetValue(int value) 
{
	if(m_pInt == nullptr)
	{
		m_pInt = new int(0);
	}
	*m_pInt = value;
}

//Destructor
Integer::~Integer() 
{
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}