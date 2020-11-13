#include <iostream>
#include <string>
#include "Integer.hpp"
using namespace std;

#define OPERATION(x) cout << "############### operation: '" << #x << "' ############### " << endl; x
int Integer::counter = 0;

Integer operator+(const Integer& obj1, const Integer& obj2)
{
	cout << "Adding " << obj1.name << " and " << obj2.name << endl;
	cout << "lhs of type lv and value " << *obj1.value << endl;
	cout << "rhs of type lv and value " << *obj2.value << endl;
	
	Integer res;
	*res.value = *obj1.value + *obj2.value;
	cout << "Addition result is " << *res.value << endl;
	return res;
}

Integer&& operator+(Integer&& obj1, const Integer& obj2)
{
	cout << "Adding " << obj1.name << " and " << obj2.name << endl;
	cout << "lhs of type rv and value " << *obj1.value << endl;
	cout << "rhs of type lv and value " << *obj2.value << endl;
	
	*obj1.value = *obj1.value + *obj2.value;
	cout << "Addition result is " << *obj1.value << endl;
	return std::move(obj1);
}

Integer&& operator+(const Integer& obj1, Integer&& obj2)
{
	cout << "Adding " << obj1.name << " and " << obj2.name << endl;
	cout << "lhs of type lv and value " << *obj1.value << endl;
	cout << "rhs of type rv and value " << *obj2.value << endl;
	
	*obj2.value = *obj1.value + *obj2.value;
	cout << "Addition result is " << *obj2.value << endl;
	return std::move(obj2);
}

Integer&& operator+(Integer&& obj1, Integer&& obj2)
{
	cout << "Adding " << obj1.name << " and " << obj2.name << endl;
	cout << "lhs of type rv and value " << *obj1.value << endl;
	cout << "rhs of type rv and value " << *obj2.value << endl;
	
	*obj1.value = *obj1.value + *obj2.value;
	cout << "Addition result is " << *obj1.value << endl;
	return std::move(obj1);
}

int main()
{
	{
		OPERATION(Integer a(1));
		OPERATION(Integer b(a));
		OPERATION(b.setValue(2));
		OPERATION(Integer c = a);
		OPERATION(c.setValue(3));
		OPERATION(Integer d(a + c));
		OPERATION(Integer e = b + c);
		OPERATION(Integer g = a + b + c);
		OPERATION(Integer h(std::move(a)));
		OPERATION(Integer i = std::move(b));
		OPERATION(Integer j);
		OPERATION(j = c);
		OPERATION(Integer l = std::move(c + d));
		OPERATION(Integer n = std::move(Integer()));
		OPERATION(n = std::move(l));
	}
	{
		OPERATION(Integer o);
		OPERATION(o = (Integer(1) + Integer(2)) + (Integer(3) + Integer(4)));
	}
	return 0;
}