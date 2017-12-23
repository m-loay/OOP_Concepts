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

	/*Crate two lists*/
	cout<<"Crate two lists"<<endl;
	list<int>listOne;
	list<int>listTwo;

	/*Add numbers to list one*/
	cout<<"Add numbers to list one"<<endl;
	listOne.push_front(1);
	listOne.push_back(2);
	listOne.push_front(3);
	listOne.push_back(4);

	/*Print ListOne*/
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	/*Sort ListOne*/
	cout<<"\nSort ListOne"<<endl;
	listOne.sort();
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	/*Add Array to list two*/
	cout<<"\nAdd Array to list two"<<endl;
	listTwo.insert(listTwo.begin(),array,array+4);
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	cout<<"\nremove listTwo elements and insert at end of listOne"<<endl;
	listOne.splice(listOne.end(),listTwo);	cout<<"Print ListOne"<<endl;
	cout<<"Print ListOne"<<endl;
	printList(listOne);
	cout<<endl;
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*Sort ListOne*/
	cout<<"\nSort ListOne"<<endl;
	listOne.sort();
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	/*Add list to list two*/
	cout<<"\nAdd list to list two"<<endl;
	listTwo.insert(listTwo.begin(),array,array+4);
	listTwo.sort();
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*remove listTwo elements and insert at end of listOne in sorted order*/
	cout<<"\nremove listTwo elements and insert at end of listOne in sorted order"<<endl;
	listOne.merge(listTwo);
	cout<<"Print ListOne"<<endl;
	printList(listOne);
	cout<<endl;
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*remove first and last element from list*/
	cout<<"\nremove first and last element from list"<<endl;
	listOne.pop_front();
	listOne.pop_back();
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	/*remove dups list*/
	cout<<"\nremove dups list"<<endl;
	listOne.unique();
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	/*Swap two lists*/
	cout<<"\nSwap two lists"<<endl;
	listOne.swap(listTwo);
	cout<<"Print ListOne"<<endl;
	printList(listOne);
	cout<<endl;
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*assign from begin to end in list two to list one*/
	cout<<"\nassign from begin to end in list two to list one-"<<endl;
	listOne.assign(listTwo.begin(),listTwo.end());
	cout<<"Print ListOne"<<endl;
	printList(listOne);
	cout<<endl;
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*remove listTwo elements and insert at end of listOne in sorted order*/
	cout<<"\nremove listTwo elements and insert at end of listOne in sorted order"<<endl;
	listOne.merge(listTwo);
	cout<<"Print ListOne"<<endl;
	printList(listOne);
	cout<<endl;
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*Remove All 4s*/
	cout<<"\nRemove All 4s"<<endl;
	listOne.remove(4);
	cout<<"Print ListOne"<<endl;
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
