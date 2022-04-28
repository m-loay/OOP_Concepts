#pragma once
#include <iostream>
class Array 
{
    friend std::ostream &operator<<( std::ostream &, const Array & );
	friend std::istream &operator>>( std::istream &, Array & );
public:
    //Default constructor
    Array();

    //Default destructor
    ~Array();

    //Parameterized constructor
    Array(int);

    //Copy constructor
    Array(const Array &);

    //Move constructor
    Array(Array &&);

    //overload = assignemet
    const Array& operator=(const Array &);

    //overload = assignemet Move Constructor
    const Array& operator=(Array &&);

    //overload == assignemet
    bool operator==(const Array &)const;
    bool operator!= (const Array &right) const
    {
        return !(*this == right);
    }

    //overload + assignemet
    Array operator+(const Array &);

    //overload pre-increment x++ assignemet
    const Array& operator++();

    //overload post-increment ++x assignemet
    Array operator++(int);

	//overload array subscribt
    int &operator[](int);
	int operator[](int)const;

    //getter of array size
    int getSize(void)const;

private:
    int m_size{10};
    int *m_pInt{new int[m_size]{0}};
    static int counter;
    std::string name;
    void assignName();
};
