#include<iostream>
#include <string>
#include "Integer.h"
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x
Integer Add(const Integer &a, const Integer &b)
{
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue()) ;
	return temp ;
}

Integer AddElison(int a, int b)
{
	Integer temp(a+b);
	return temp;
}

void print(const Integer &obj)
{
	std::cout<<"object -->"<<obj.GetName()<<" value = "<<obj.GetValue()<<std::endl;
}

int main() 
{
	//create object a ,b from class Integer
	OPERATION( Integer a(1));
	print(a);

	OPERATION( Integer b(3));
	print(b);

	//use temp object return from add to set object a
	OPERATION(a.SetValue(Add(a,b).GetValue()));
	print(a);

	//Print a once again as temp value(R-value) by using std::move
	OPERATION(print(std::move(a)));

	//reset object a with 5 using copy elision
	OPERATION(a = AddElison(2,3));
	print(a);

	//Add two objects in object's constructor
	OPERATION(Integer c (a+b));
	print(c);

	//Add two objects in object's constructor using move
	OPERATION(Integer d(c+a));
	print(d);

	//Add two objects then assignment semantics
	OPERATION(c = a+b);
	print(c);

	//Assignment semantics
	OPERATION(d = std::move(a+b));
	print(d);

	return 0;
}