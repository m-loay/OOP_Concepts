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

	//check object a using debugger
	//reset object a with 5
	OPERATION(a = AddElison(2,3));
	print(a);

	//Add two objects
	OPERATION(Integer c (a+b));
	print(c);

	//Integer sum ;
	OPERATION(Integer d(std::move(a+b)));
	print(d);

	OPERATION(c = a+b);
	print(c);

	OPERATION(d = b);
	print(d);

	return 0;
}