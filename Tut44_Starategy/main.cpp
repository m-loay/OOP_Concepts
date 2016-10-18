/*
 * main.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: modys
 */

#include"Startegy.h"

int main ()
{

	    Merge merge;
	    Quick quick;
	    Heap heap;
	    Strategy algo;

	    algo.set_sort(&merge);
	    algo.sort();

	    algo.set_sort(&quick);
	    algo.sort();

	    algo.set_sort(&heap);
	    algo.sort();

	    return 0;
}


