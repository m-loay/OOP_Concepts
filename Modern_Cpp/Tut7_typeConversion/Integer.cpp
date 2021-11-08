#include "Integer.h"
#include <iostream>

//Initialize the provate static member
int Integer::counter = 0;

/**
 * @brief Default Construct a new Integer:: Integer object
 * 
 */
Integer::Integer() 
{
    assignName();
    std::cout << name << " --> Integer()" << std::endl;
}

/**
 * @brief Parameterized constructor a new Integer:: Integer object.
 * 
 * @param value {int}.
 */
Integer::Integer(int value): Integer() 
{
    std::cout << name << " --> Integer(int)" << std::endl;
    *m_pInt = value;
}

/**
 * @brief Copy Construct a new Integer:: Integer object.
 * 
 * @param obj Integer:: Integer object.
 */
Integer::Integer(const Integer & obj) 
{
    assignName();
    std::cout << "Integer(const int&) " << name << " --> from obj " << obj.name <<std::endl;
    m_pInt = new int(*obj.m_pInt);
}


/**
 * @brief Move Construct a new Integer:: Integer object.
 * 
 * @param obj Integer:: Integer &&object (R-Value).
 */
Integer::Integer(Integer && obj) 
{
    std::cout << "Integer(int&&) " << name << " --> from obj " << obj.name <<std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

/**
 * @brief overload = assignemet.
 * 
 * @param rhs {const Integer&}.
 * @return const Integer& .
 */
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


/**
 * @brief overload = assignemet Move Constructor
 * 
 * @param rhs {Integer&&} (R-Value).
 * @return const Integer& 
 */
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


/**
 * @brief overload + assignemet.
 * 
 * @param rhs {const Integer &}.
 * @return Integer. 
 */
Integer Integer::operator+(const Integer &rhs)const
{
    std::cout <<"operator+(const Integer &)" << name << " --> from obj " << rhs.name <<std::endl;
    Integer temp;
    *temp.m_pInt = *m_pInt + *rhs.m_pInt;
    return temp;
}


/**
 * @brief overload pre-increment ++x assignemet.
 * 
 * @return const Integer&. 
 */
const Integer& Integer::operator++()
{
    std::cout <<"++operator" << std::endl;
    ++(*m_pInt);
    return *this;
}


/**
 * @brief overload post-increment x++ assignemet.
 * 
 * @return Integer .
 */
Integer Integer::operator++(int)
{
    std::cout <<"operator++" << std::endl;
    Integer temp(*this);
    ++(*m_pInt);
    return temp;
}


/**
 * @brief overload == assignemet operator.
 * 
 * @param rhs {const Integer &}.
 * @return true if objects are equals.
 * @return false if objects are not equals.
 */
bool Integer:: operator==(const Integer &rhs)const
{
    std::cout <<"operator==" << std::endl;
    return *m_pInt == *rhs.m_pInt;
}


/**
 * @brief int operator overload.
 * 
 * @return int. 
 */
Integer::operator int ()
{
    std::cout << "operator int" << name<< std::endl;
    return *m_pInt;
}

//setter & getter
/**
 * @brief GetValue a getter method for value.
 * 
 * @return int. 
 */
int Integer::GetValue() const 
{
    return *m_pInt;
}

/**
 * @brief GetName a getter method for name.
 * 
 * @return std::string.
 */
std::string Integer::GetName() const 
{
    return name;
}

/**
 * @brief SetValue a setter method for value.
 * 
 * @param value {int}.
 */
void Integer::SetValue(int value) 
{
    *m_pInt = value;
}

/**
 * @brief assignName assign rondom name for objects.
 * 
 */
void Integer:: assignName()
{
    char c = 'a' + counter;
    name = std::string(1, c);
    counter ++;
}

/**
 * @brief Destroy the Integer:: Integer object.
 * 
 */
Integer::~Integer() 
{
    std::cout << "~Integer()" <<" "<< GetValue() <<std::endl;
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