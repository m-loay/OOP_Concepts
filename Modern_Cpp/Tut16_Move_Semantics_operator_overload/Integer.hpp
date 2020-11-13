
#include <iostream>
#pragma once
using namespace std;

class Integer
{
public:
	Integer();
	Integer(int);
	Integer(const Integer& i);
	Integer(Integer && src);
	Integer& operator=(const Integer& src);
	Integer& operator=(Integer&& src);
	~Integer();
	void setValue(int avalue);
	friend Integer operator+(const Integer&, const Integer&);
	friend Integer&& operator+(Integer&&, const Integer&);
	friend Integer&& operator+(const Integer&, Integer&&);
	friend Integer&& operator+(Integer&&, Integer&&);
private:
	int* value;
	static int counter;
	string name;
	void printValue();
	void assignName();
};
