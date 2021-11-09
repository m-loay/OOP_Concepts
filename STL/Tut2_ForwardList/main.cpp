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
#include <forward_list>

using namespace std;


void fListIntializationMethods(void);
void fListLogicalOperations(void);
void fListModifiers(void);
template <typename T> void printList(const forward_list<T> &refList);

int main ()
{
    /*******************************************************************************
     *  Initialization of Vectors                                                  *
     *******************************************************************************/
    fListIntializationMethods();

    /*******************************************************************************
     *  Vector Logical Operations                                                  *
     *******************************************************************************/
    fListLogicalOperations();

    /*******************************************************************************
     *  Vector Modifiers                                                           *
     *******************************************************************************/
    fListModifiers();
}

void fListIntializationMethods(void)
{
	//1)Initialize flist direct method
	forward_list<int> flist1{10,20,30,40,50};
	std::cout<<"flist1: "<<std::endl;
	printList(flist1);

	//2)Initialize using assign with intialize stander
	forward_list<int> flist2;
	flist2.assign({1, 2, 3});
	std::cout<<"flist2: "<<std::endl;
	printList(flist2);

	//3)Initialize using assign number_of_repetition and element_value
	forward_list<int> flist3;
	flist3.assign(5, 10);
	std::cout<<"flist3: "<<std::endl;
	printList(flist3);

	//4)Initialize using assign number_of_repetition and element_value
	forward_list<int> flist4;
	flist4.emplace_front(4);
	flist4.push_front(5);
	flist4.push_front(50);
	flist4.push_front(100);
	flist4.insert_after(std::next(flist4.begin(),2), {7,6});
	std::cout<<"flist4: "<<std::endl;
	printList(flist4);
}

void fListLogicalOperations(void)
{
	forward_list<int> flist1{10,20,30,40,50};
	std::cout<<"flist1: "<<std::endl;
	printList(flist1);

	forward_list<int> flist2(flist1);
	std::cout<<"flist2: "<<std::endl;
	printList(flist2);

	if(flist1 == flist2)
	{
		std::cout<<" flist1 and flist2 are equal"<<std::endl;
	}
	else
	{
		std::cout<<" flist1 and flist2 are not equal"<<std::endl;
	}
}

void fListModifiers(void)
{
	forward_list<int> listOne{4,50,-20,30,4,30,4,30,4,500};
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	forward_list<int> listTwo{9,0,8,6,3};
	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*Sort ListOne*/
	cout<<"\nSort ListOne"<<endl;
	listOne.sort();
	cout<<"Print ListOne"<<endl;
	printList(listOne);


	cout<<"\nremove listTwo elements and insert at end of listOne"<<endl;
	listOne.splice_after(std::next(listOne.begin(),9),listTwo);	
	cout<<"Print ListOne"<<endl;
	printList(listOne);


	/*remove listTwo elements and insert at end of listOne in sorted order*/
	cout<<"\nremove listTwo elements and insert at end of listOne in sorted order"<<endl;
	listOne.merge(listTwo);
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

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

	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*remove listTwo elements and insert at end of listOne in sorted order*/
	cout<<"\nremove listTwo elements and insert at end of listOne in sorted order"<<endl;
	listOne.merge(listTwo);
	cout<<"Print ListOne"<<endl;
	printList(listOne);

	cout<<"Print ListTWO"<<endl;
	printList(listTwo);

	/*Remove All 4s*/
	cout<<"\nRemove All 4s"<<endl;
	listOne.remove(4);
	cout<<"Print ListOne"<<endl;
	printList(listOne);

}

template <typename T>
void printList(const forward_list<T> &refList)
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
	std::cout<<std::endl;
}