/*
 * main.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: modys
 */

#include "../Tut13_Starategy/Startegy.h"

int main ()
{
	/*Create Array to be sorted*/
	int p[6]={3,2,6,1,9,4};

	/*Create objects of all sorting alogorithms*/
	Merge *merge =new Merge(6,p);
	Qsort *qsort = new Qsort(6,p);
	BubbleSort *bubble = new BubbleSort(6,p);
	SelectionSort *selection = new SelectionSort(6,p);
	InsertionSort *insert = new InsertionSort(6,p);

	/*Create object of startegy to activate each sorting algorithm*/
	Strategy algo;

	/*Activate merge sort*/
	algo.set_sort(merge);
	algo.sort();

	/*Activate quick sort*/
	algo.set_sort(qsort);
	algo.sort();

	/*Activate bubble sort*/
	algo.set_sort(bubble);
	algo.sort();

	/*Activate selection sort*/
	algo.set_sort(selection);
	algo.sort();

	/*Activate insertion sort*/
	algo.set_sort(insert);
	algo.sort();

	/*Delete memory allocation*/
	delete merge;
	delete qsort;
	delete bubble;
	delete selection;
	delete insert;

	return (0);
}


