/*
 * main.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: modys
 */

#include"Startegy.h"

int main ()
{

	int p[6]={3,2,6,1,9,4};
	Merge *merge =new Merge(6,p);
	Qsort *qsort = new Qsort(6,p);
	BubbleSort *bubble = new BubbleSort(6,p);
	SelectionSort *selection = new SelectionSort(6,p);
	InsertionSort *insert = new InsertionSort(6,p);
	Strategy algo;

	algo.set_sort(merge);
	algo.sort();

	algo.set_sort(qsort);
	algo.sort();

	algo.set_sort(bubble);
	algo.sort();

	algo.set_sort(selection);
	algo.sort();

	algo.set_sort(insert);
	algo.sort();

	delete merge;
	delete qsort;
	delete bubble;
	delete selection;
	delete insert;

	return 0;
}


