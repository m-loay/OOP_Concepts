#include "Array.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include<iomanip>

//Initialize the provate static member
int Array::counter = 0;

Array::Array()
{
    assignName();
    std::cout << name << " --> Integer()" << std::endl;
}

Array::~Array()
{
    std::cout<<"Destructor is Called"<<std::endl;
    delete [] m_pInt;
}

Array::Array(int size)
{
    assignName();
    std::cout<< name<<"Array(int)"<<std::endl;
    m_size = size;
    m_pInt = new int[m_size]{0};
}

Array::Array(const Array &objCpy)
{
    assignName();
    std::cout << "Array(const int&) " << name << " --> from obj " << objCpy.name <<std::endl;
    if(&objCpy != this)
    {
        m_size = objCpy.m_size;
        delete[] m_pInt;
        m_pInt = new int[m_size]{0};
        memcpy(m_pInt, objCpy.m_pInt, sizeof(int)*m_size);
    }
}

Array::Array(Array &&rvalCpy)
{
    assignName();
    std::cout << "Array(int&&) " << name << " --> from obj " << rvalCpy.name <<std::endl;
    if(&rvalCpy != this)
    {
        m_size = rvalCpy.m_size;
        delete [] m_pInt;
        m_pInt = rvalCpy.m_pInt;
        rvalCpy.m_pInt = nullptr;
    }
}

const Array& Array::operator=(const Array &rhs)
{
    std::cout << "operator=(const Array &) " << name << " --> from obj " << rhs.name <<std::endl;
    if(&rhs != this)
    {
        m_size = rhs.m_size;
        delete [] m_pInt;
        m_pInt = new int[m_size]{0};
        memcpy(m_pInt, rhs.m_pInt, sizeof(int)*m_size);
    }
    return *this;
}

const Array& Array::operator=(Array &&rvalRhs)
{
     std::cout << "operator=(const Array &&)" << name << " --> from obj " << rvalRhs.name <<std::endl;
    if(&rvalRhs != this)
    {
        m_size = rvalRhs.m_size;
        delete m_pInt;
        m_pInt = rvalRhs.m_pInt;
        rvalRhs.m_pInt = nullptr;
    }
    return *this;
}

bool Array::operator==(const Array &rhs) const
{
    std::cout<<"Array::operator==(const Array &rhs)"<<std::endl;
    bool flag(true);
    if((&rhs != this) && (m_size == rhs.m_size))
    {
        for (int i = 0; i < m_size; i++)
        {
            if(m_pInt[i] != rhs.m_pInt[i])
            {
                flag = false;
                break;
            }
        }        
    }
    else
    {
        flag = false;
    }
    return flag;
}

Array Array::operator++(int)
{
    std::cout <<"operator++" << std::endl;
    
    Array temp(*this);
    for (int i = 0; i < m_size; i++)
    {
        m_pInt[i]++;
    }
    return temp;
}

const Array& Array::operator++()
{
    std::cout <<"++operator" << std::endl;
    for (int i = 0; i < m_size; i++)
    {
        m_pInt[i]++;
    }
    return *this;
}


Array Array::operator+(const Array &rhs)
{
    std::cout <<"operator+(const Integer &)" << name << " --> from obj " << rhs.name <<std::endl;
    Array temp;
    delete[] temp.m_pInt;
    int minSize(std::min(m_size, rhs.m_size));
    if(m_size > rhs.m_size)
    {
        temp.m_pInt = new int[m_size]{0};
        memcpy(temp.m_pInt, m_pInt, sizeof(int)*m_size);
    }
    else
    {
        temp.m_pInt = new int[rhs.m_size]{0};
        memcpy(temp.m_pInt, rhs.m_pInt, sizeof(int)*m_size);       
    }

    for(int i=0; i< minSize; i++)
    {
        temp.m_pInt[i] = m_pInt[i] + rhs.m_pInt[i];
    }
    return temp;
}

/**
 * @brief assignName assign rondom name for objects.
 * 
 */
void Array:: assignName()
{
    char c = 'a' + counter;
    name = std::string(1, c);
    counter ++;
}

int Array::getSize(void) const
{
    return m_size;
}

std::ostream &operator<<(std::ostream &output , const Array &a )
{
	int i;

    if(a.m_pInt != nullptr)
    {
        // output private ptr-based array
        for(i=0;i< a.m_size;i++)
        {
            output << std::setw( 12) << a.m_pInt[ i ];

            if( ( i + 1) % 4== 0) // 4 numbers per row of output
                output << std::endl;
        }// end for

        if( i % 4!= 0) // end last line of output
            output << std::endl;

    }
    else
    {
        output<<"The array is Empty"<<std::endl;
    }

	return output; // enables cout << x << y;
}

std::istream &operator>>(std::istream &input , Array &a)
{
	for( int i = 0; i < a.m_size; i++ )
		input >> a.m_pInt[ i ];
	return input; // enables cin >> x >> y;
}

int &Array::operator[](int sub)
{
	if(sub<0|| sub>m_size)
	{
		std::cerr<<"Error Sub"<<sub<<"out of range"<<std::endl;
		exit(1);
	}
	return m_pInt[sub];
}

int Array::operator[](int sub)const
{
	if(sub<0|| sub>m_size)
	{
		std::cerr<<"Error Sub"<<sub<<"out of range"<<std::endl;
		exit(1);
	}
	return m_pInt[sub];
}