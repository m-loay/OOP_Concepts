/*
 * Startegy.h
 *
 *  Created on: Oct 19, 2016
 *      Author: modys
 */

#ifndef STARTEGY_H_
#define STARTEGY_H_
#include <iostream>
#include <vector>

using namespace std;

class SortBehavior
{
public:
	SortBehavior ()
{
		cout<<"SortBehavior  Called"<<endl;
}
	virtual ~SortBehavior ()
	{
		cout<<"~SortBehavior  Called"<<endl;
	}
	virtual void sort()= 0;
};

class SelectionSort: public SortBehavior
{

public:
	// constructor, inits vector
	SelectionSort(int vectorSize,int *p)
	{
		cout<<"SelectionSort  Called"<<endl;
		// validate vectorSize
		size = (vectorSize > 0 ? vectorSize : 10);

		// seed random number generator using current time
		//srand(time(0));

		// fill vector with random ints in range 10 to 99
		for (int i = 0; i < size; i++)
		{
			data.push_back(p[i]);
		}
	}

	~SelectionSort()
	{
		cout<<"~SelectionSort  Called"<<endl;
	}

	// sort vector using merge sort
	void sort()
	{
		selectionSort();
		displayElements();
	}

	// display vector elements
	void displayElements() const
	{
		for(int i = 0; i < size; i++)
		{
			cout << " " << data[i];
		}
		cout<<endl;
	}


private:
	//vector size
	int size;

	// vecotr of ints
	vector<int> data;

	void selectionSort()
	{
		int count,count2,imin;
		for(count=0;count<size-1;count++)
		{
			imin=count;
			for (count2 =count+1; count2 < size; count2++)
			{
				if(data[count2] < data[imin]) imin=count2;
			}
			swap(data[count] , data[imin]);
		}
	}

};

class InsertionSort: public SortBehavior
{

public:
	// constructor, inits vector
	InsertionSort(int vectorSize,int *p)
	{
		cout<<"selection_sort  Called"<<endl;
		// validate vectorSize
		size = (vectorSize > 0 ? vectorSize : 10);

		// seed random number generator using current time
		//srand(time(0));

		// fill vector with random ints in range 10 to 99
		for (int i = 0; i < size; i++)
		{
			data.push_back(p[i]);
		}
	}

	~InsertionSort()
	{
		cout<<"~InsertionSort  Called"<<endl;
	}

	// sort vector using merge sort
	void sort()
	{
		insertionSort();
		displayElements();
	}

	// display vector elements
	void displayElements() const
	{
		for(int i = 0; i < size; i++)
		{
			cout << " " << data[i];
		}
		cout<<endl;
	}


private:
	//vector size
	int size;

	// vecotr of ints
	vector<int> data;

	void insertionSort()
	{
		int count,hole,value;
		for (count =1; count < size; count++)
		{
			value=data[count];
			hole=count;

			while(hole>0 && data[hole-1]>value)
			{
				data[hole]=data[hole-1];
				hole=hole-1;
			}
			data[hole]=value;
		}
	}

};


class BubbleSort: public SortBehavior
{

public:
	// constructor, inits vector
	BubbleSort(int vectorSize,int *p)
	{
		cout<<"BubbleSort  Called"<<endl;
		// validate vectorSize
		size = (vectorSize > 0 ? vectorSize : 10);

		// seed random number generator using current time
		//srand(time(0));

		// fill vector with random ints in range 10 to 99
		for (int i = 0; i < size; i++)
		{
			data.push_back(p[i]);
		}
	}

	~BubbleSort()
	{
		cout<<"~BubbleSort  Called"<<endl;
	}

	// sort vector using merge sort
	void sort()
	{
		bubbleSort();
		displayElements();
	}

	// display vector elements
	void displayElements() const
	{
		for(int i = 0; i < size; i++)
		{
			cout << " " << data[i];
		}
		cout<<endl;
	}


private:
	//vector size
	int size;

	// vecotr of ints
	vector<int> data;

	void bubbleSort ()
	{
		int count,count2;

		for (count = 0; count < size; count++)
		{
			for (count2 = 0; count2 < size-1; count2++)
			{
				if((data[count2]> data[count2+1]))
				swap(data[count2], data[count2+1]);
			}
		}
	}
};


class Merge: public SortBehavior
{

public:
	// constructor, inits vector
	Merge(int vectorSize,int *p)
{
		cout<<"Merge  Called"<<endl;
		// validate vectorSize
		size = (vectorSize > 0 ? vectorSize : 10);

		// seed random number generator using current time
		//srand(time(0));

		// fill vector with random ints in range 10 to 99
		for (int i = 0; i < size; i++)
		{
			data.push_back(p[i]);
		}
}

	~Merge()
	{
		cout<<"~Merge  Called"<<endl;
	}

	// sort vector using merge sort
	void sort()
	{
		sortSubVector(0, size - 1);
		displayElements();
	}

	// display vector elements
	void displayElements() const
	{
		for(int i = 0; i < size; i++)
		{
			cout << " " << data[i];
		}
		cout<<endl;

	}


private:
	//vector size
	int size;

	// vecotr of ints
	vector<int> data;

	// sort subvector
	void sortSubVector(int low, int high)
	{
		// test base case: size of vector = 1
		if((high - low) >= 1)
		{
			// calculate middle of vector
			int middle1 = (low + high) / 2;

			// calculate next element over
			int middle2 = middle1 + 1;

			// split vector in half; sort each half (recursive calls)
			sortSubVector(low, middle1);
			sortSubVector(middle2, high);

			// merge two sorted vectors after split calls return
			merge(low, middle1, middle2, high);
		}
	}

	// merge two sorted vectors
	void merge(int left, int middle1, int middle2, int right)
	{
		// index into left subvector
		int leftIndex = left;
		// index into right subvector
		int rightIndex = middle2;
		// index into temporary working vector
		int combinedIndex = left;
		// working vector
		vector<int> combined (size);

		// merge vectors until reaching end of either
		while (leftIndex <= middle1 && rightIndex <= right)
		{
			// place smaller of two current elements into result
			// and move to next space in vector
			if(data[leftIndex] <= data[rightIndex])
			{
				combined[combinedIndex++] = data[leftIndex++];
			}
			else
			{
				combined[combinedIndex++] = data[rightIndex++];
			}
		}


		// copy in the rest of the right vector
		while(rightIndex <= right)
		{
			combined[combinedIndex++] = data[rightIndex++];
		}

		// copy in the rest of the left vector
		while(leftIndex <= middle1)
		{
			combined[combinedIndex++] = data[leftIndex++];
		}

		// copy values back into original vector
		for(int i = left; i <= right; i++)
		{
			data[i] = combined[i];
		}

	}

};

class Qsort: public SortBehavior
{

public:
	// constructor, inits vector
	Qsort(int vectorSize,int *p)
	{
		cout<<"Qsort  Called"<<endl;
		// validate vectorSize
		size = (vectorSize > 0 ? vectorSize : 10);

		// seed random number generator using current time
		//srand(time(0));

		// fill vector with random ints in range 10 to 99
		for (int i = 0; i < size; i++)
		{
			data.push_back(p[i]);
		}
	}

	~Qsort()
	{
		cout<<"~Qsort  Called"<<endl;
	}

	// sort vector using merge sort
	void sort()
	{
		quickSort(0, size - 1);
		displayElements();
	}

	// display vector elements
	void displayElements() const
	{
		for(int i = 0; i < size; i++)
		{
			cout << " " << data[i];
		}
		cout<<endl;
	}


private:
	//vector size
	int size;

	// vecotr of ints
	vector<int> data;

	// sort subvector
	int partition(int start , int end)
	{
		int x = data[end];
		int i = start - 1;
		int j;
		for(j = start; j <= end-1; j++)
		{
			if(data[j] <= x)
			{
				i = i + 1;
				swap(data[i], data[j]);
			}
		}
		swap(data[i+1], data[end]);
		return i+1;
	}

	// merge two sorted vectors
	void quickSort(int start , int end)
	{
		if(start<end)
		{
			int q = partition(start, end);
			quickSort(start, q-1);
			quickSort(q+1, end);
		}
	}

};

class Strategy
{
private:
	SortBehavior* m_sort;

public:
	Strategy():m_sort(0)
{
		cout<<"Strategy Called"<<endl;
}
	~Strategy()
	{
		cout<<"~Strategy Called"<<endl;
	}
	void set_sort(SortBehavior* s){
		m_sort = s;
	}

	void sort()
	{
		m_sort->sort();
	}
};

#endif /* STARTEGY_H_ */
