#include "Integer.hpp"  

Integer::Integer() 
{

}

Integer::Integer(int avalue = 0) : name("tmp")
{
    assignName();
    cout << "Normal constructing obj '" << name << "'" << endl;
    value = new int;
    *value = avalue;
    printValue();
}

Integer:: Integer(const Integer& i) : name("tmp")
{
    assignName();
    cout << "Copy constructing obj '" << name << "' from obj '" << i.name << "'" << endl;
    value = new int;
    *value = *i.value;
    printValue();
}

Integer::Integer(Integer && src) : value(src.value), name("tmp")
{
    assignName();
    cout << "Move constructing obj '" << name << "' from obj '" << src.name << "'" << endl;
    src.value = nullptr;
    printValue();
    
}

Integer& Integer:: operator=(const Integer& src)
{
    cout << "Assigning '" << src.name << "' to '" << name << "'" << endl;
    *value = *src.value;
    printValue();
    
    return *this;
}

Integer& Integer:: operator=(Integer&& src)
{
    cout << "Move assigning '" << src.name << "' to '" << name << "'" << endl;
    value = src.value;
    src.value = nullptr;
    printValue();
    
    return *this;
}

Integer::~Integer()
{
    cout << "Destroying " << name << endl;
    if(value != nullptr)
    {
        delete value;
    }
    else
    {
        cout << name << "'s value is moved" << endl;
    }
}

void Integer:: setValue(int avalue)
{
    *value = avalue;
    cout << "Set '" << name << "' value to " << avalue << endl;
}

void Integer:: printValue()
{
    cout << "value = " << *value << endl;
}

void Integer:: assignName()
{
    char c = 'a' + counter;
    name = string(1, c);
    counter ++;
}