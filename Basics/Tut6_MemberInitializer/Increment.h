/*
 * Increment.h
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#ifndef INCREMENT_H_
#define INCREMENT_H_
#include "iostream"
using namespace std;

class Increment {
public:
	Increment(int c = 0, int i = 1);
	~Increment();
	void addIncrement ();
	void print () const;

private:
	int count;
	const int increment;
};

#endif /* INCREMENT_H_ */
