#include<iostream>
#include <string>
#include "Integer.h"

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

void print(std::string name, Integer obj)
{
	std::cout<<"object -->"<<name<<" value = "<<obj.GetValue()<<std::endl;
}

int main() 
{
	//create object a ,b from class Integer
	Integer a(1), b(3);

	//use temp object return from add to set object a
	a.SetValue(Add(a,b).GetValue());
	print("a",a);

	//Print a once again as temp value(R-value) by using std::move
	print("a",std::move(a));

	//check object a using debugger
	//reset object a with 5
	a = AddElison(2,3);
	print("a",a);

	//Add two objects
	Integer sum (std::move(a+b));
	print("sum",sum);

	//Integer sum ;
	sum =std::move(a+b);

	return 0;
}