/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: modys
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

template <typename T> void printList(const list<T> &refList);

int main()
{
	int array[4] = {2,6,4,8};
	cout<<"Crate two lists"<<endl;
	list<int>listOne;
	list<int>listTwo;

	cout<<"Add list to list one"<<endl;
	listOne.push_front(1);
	listOne.push_back(2);
	listOne.push_front(3);
	listOne.push_back(4);

	cout<<"Print ListOne"<<endl;
	printList(listOne);

	cout<<"\nSort ListOne"<<endl;
	listOne.sort();
	printList(listOne);

	cout<<"\nAdd list to list two"<<endl;
	listTwo.insert(listTwo.begin(),array,array+4);
	printList(listTwo);

	cout<<"\n remove listTwo elements and insert at end of listOne"<<endl;
	listOne.splice(listOne.end(),listTwo);	cout<<"Print ListOne"<<endl;
	printList(listOne);
	cout<<endl;
	printList(listTwo);

	cout<<"\nSort ListOne"<<endl;
	listOne.sort();
	printList(listOne);

	cout<<"\nAdd list to list two"<<endl;
	listTwo.insert(listTwo.begin(),array,array+4);
	listTwo.sort();
	printList(listTwo);

	cout<<"\n remove listTwo elements and insert at end of listOne in sorted order"<<endl;
	listOne.merge(listTwo);
	printList(listOne);
	cout<<endl;
	printList(listTwo);

	cout<<"\n remove first and last element from list"<<endl;
	listOne.pop_front();
	listOne.pop_back();
	printList(listOne);

	cout<<"\n remove dups list"<<endl;
	listOne.unique();
	printList(listOne);

	cout<<"\nSwap two lists"<<endl;
	listOne.swap(listTwo);
	printList(listOne);
	cout<<endl;
	printList(listTwo);

	cout<<"\nassign from begin to end in list two to list one-"<<endl;
	listOne.assign(listTwo.begin(),listTwo.end());
	printList(listOne);
	cout<<endl;
	printList(listTwo);

	cout<<"\n remove listTwo elements and insert at end of listOne in sorted order"<<endl;
	listOne.merge(listTwo);
	printList(listOne);
	cout<<endl;
	printList(listTwo);

	cout<<"\nRemove All 4s"<<endl;
	listOne.remove(4);
	printList(listOne);

}

template <typename T>
void printList(const list<T> &refList)
{
	if(refList.empty())
	{
		cout<<"The list is Empty"<<endl;
	}
	else
	{
		ostream_iterator<T> output(cout," ");
		copy(refList.begin(),refList.end(),output);
	}
}
