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
	// --> Integer(1)
	OPERATION( Integer a(1));
	print(a);

	// --> Integer(1)
	OPERATION( Integer b(3));
	print(b);

	//use temp object return from add to set object a
	// --> Temp Integer() --> Temp ~Integer()
	OPERATION(a.SetValue(Add(a,b).GetValue()));
	print(a);

	//Print a once again as temp value(R-value) by using std::move
	// --> R-value binds to const ref (L-value)
	OPERATION(print(std::move(a)));

	//reset object a with 5 using copy elision
	// -->Temp Integer(5) -->operator=(const Integer &&)a --> from obj Temp --> Temp ~Integer()
	OPERATION(a = AddElison(2,3));
	print(a);

	//Add two objects in object's constructor
	// --> operator+(const Integer &)a --> c  Integer(8)
	OPERATION(Integer c (a+b));
	print(c);

	//Add two objects in object's constructor using move
	// --> operator+(const Integer &)c --> d  Integer(13)
	OPERATION(Integer d(c+a));
	print(d);

	//Add two objects then assignment semantics
	// --> operator+(const Integer &)a --> e  Integer()+update internal variable 
	//--> operator=(const Integer &&)c from obj e --> e ~Integer()
	OPERATION(c = a+b);
	print(c);

	//Assignment semantics
	// --> operator+(const Integer &)a --> e  Integer()+update internal variable 
	//--> operator=(const Integer &&)c from obj e --> e ~Integer()
	OPERATION(d = std::move(a+b));
	print(d);

	return 0;
}