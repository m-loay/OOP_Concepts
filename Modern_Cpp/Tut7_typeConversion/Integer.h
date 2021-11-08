#pragma once
#include <iostream>
class Integer 
{
public:
    //Default constructor
    Integer();

    //Default destructor
    ~Integer();

    //Parameterized constructor
    Integer(int value);

    //Copy constructor
    Integer(const Integer &obj);

    //Move constructor
    Integer(Integer &&obj);

    //overload = assignemet
    const Integer &operator=(const Integer &);

    //overload = assignemet Move Constructor
    const Integer &operator=(Integer &&);

    //overload + assignemet
    Integer operator+(const Integer &)const;

    //overload pre-increment x++ assignemet
    const Integer &operator++();

    //overload post-increment ++x assignemet
    Integer operator++(int);

    //overload == assignemet
    bool operator==(const Integer &)const;

    //int operator overload
    explicit operator int ();

    //setter & getter
    int GetValue()const;
    std::string GetName()const;
    void SetValue(int value);


private:
    int *m_pInt{new int(0)};
    static int counter;
    std::string name;
    void assignName();

};
