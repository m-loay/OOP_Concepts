/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>
#include "TimeBase.h"
#include<vector>
#include<string>
void SeparateOddAndEvenPointer(const int arr[],int size, int **odd,int*numOdd, int **even,int *numEven);
void SeparateOddAndEvenRef(const int arr[],int size, int *&odd,int &numOdd, int *&even,int &numEven);
void SeparateOddAndEvenVect(const std::vector<int>& arr,std::vector<int>&odd,std::vector<int>&even);

void printArray(const std::string & name , const int arr[], int size);
void printVector(const std::string & name , const std::vector<int>& arr);

/*
 * call by value
 * call by pointer
 * call by ref
 * dangof returning a reference*/
int main()
{
    int x = 0;
    /*Creating object from time base*/
    Time_Base t(0);

    /*Creating pointer and ref to the time base object*/
    Time_Base *t_ptr=&t;
    Time_Base &t_ref=t;

    /*printing time using the object and use sitters*/
    std::cout<<"The init universal Time is";
    t.printUniversal();

    cout<<"The init standard time is";
    t.printStandard();

    /*use sitter to set time and print it*/
    t_ptr->setTime(13,27,6);
    std::cout<<"The init universal Time is";
    t_ptr->printUniversal();

    std::cout<<"The init standard time is";
    t_ptr->printStandard();

    /*use sitter to set time and print invalid time*/
    t_ref.setTime(99,99,99);
    std::cout<<"The init universal Time is";
    t_ref.printUniversal();

    std::cout<<"The init standard time is";
    t_ref.printStandard();

    /*Using bad setting through function that return ref*/
    std::cout<<"Using bad setting through function that return ref"<<std::endl;

    int &h_ref=t.badSetHour(10);
    std::cout<<"The init universal Time is";
    t.printUniversal();

    std::cout<<"The init standard time is";
    t.printStandard();

    /*change time using the reference [not using sitters]*/
    h_ref=35;
    std::cout<<"h_ref= 35"<<endl;
    std::cout<<"The init universal Time is";
    t.printUniversal();

    std::cout<<"The init standard time is";
    t.printStandard();

    h_ref=3;
    std::cout<<"h_ref=15"<<endl;
    std::cout<<"The init universal Time is";
    t.printUniversal();

    std::cout<<"The init standard time is";
    t.printStandard();

    //get refernce value of counter
    std::cout<<"get &counter value = "<<t.getCounter()<<std::endl;

    //set refernce counter value to 6 and print it
    t.setCounter(5);
    std::cout<<"get &counter value = "<<t.getCounter()<<std::endl;

    //Split arrays
    int unSplit[10] = {1, 2, 3, 4, 5, 6, 6, 8, 9, 10};

    //split using pointers
    int odd_num;
    int even_num;
    int *odd = nullptr;
    int *even = nullptr;
    SeparateOddAndEvenPointer(unSplit, 10, &odd, &odd_num, &even, &even_num);
    printArray("Unsplitted Array Pointers", unSplit, 10);
    printArray("odd Array Pointers", odd, odd_num);
    printArray("even Array Pointers", even, even_num);

    //split using refernces
    delete odd;
    delete even;
    odd = nullptr;
    even = nullptr;
    SeparateOddAndEvenRef(unSplit, 10, odd, odd_num, even, even_num);
    printArray("Unsplitted Array Refs", unSplit, 10);
    printArray("odd Array Refs", odd, odd_num);
    printArray("even Array Refs", even, even_num);

    //using vector
    std::vector<int> vecUnSplit = {1, 2, 3, 4, 5, 6, 6, 8, 9, 10};
    std::vector<int> odds, evens;
    SeparateOddAndEvenVect(vecUnSplit, odds, evens);
    printVector("Unsplitted Vector", vecUnSplit);
    printVector("odds Vector", odds);
    printVector("evens Vector", evens);
}

void SeparateOddAndEvenPointer(const int arr[],int size, int **odd,int*numOdd, int **even,int *numEven)
{
    //initialize odd and even counter
    *numOdd = *numEven=0;

    //check how many odd/even numbers
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]%2 ==1)
        {
            (*numOdd)++;
        }
        else
        {
            (*numEven)++;
        }
    }

    //create two separate arrays for odd/even numbers
    *odd = new int[*numOdd];
    *even = new int [*numEven];

    //start add elements to arrays
    int oddPos=0,evenPos =0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]%2 ==1)
        {
            (*odd)[oddPos++] = arr[i];
        }
        else
        {
            (*even)[evenPos++] = arr[i];
        }
    }
}

void SeparateOddAndEvenRef(const int arr[],int size, int *&odd,int &numOdd, int *&even,int &numEven)
{
    //initialize odd and even counter
    numOdd = numEven = 0;

    //check how many odd/even numbers
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]%2 ==1)
        {
            numOdd++;
        }
        else
        {
            numEven++;
        }
    }

    //create two separate arrays for odd/even numbers
    odd = new int[numOdd];
    even = new int [numEven];

    //start add elements to arrays
    int oddPos=0,evenPos =0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]%2 ==1)
        {
            odd[oddPos++] = arr[i];
        }
        else
        {
            even[evenPos++] = arr[i];
        }
    }
}

void SeparateOddAndEvenVect(const std::vector<int>& arr,std::vector<int>&odd,std::vector<int>&even)
{
    for (const auto &i : arr)
    {
        if (i%2 == 1)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }
}

void printArray(const std::string & name , const int arr[] , int size)
{
    std::cout<<name<<" Array"<<std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
void printVector(const std::string & name , const std::vector<int>& arr)
{
    std::cout<<name<<" Vector"<<std::endl;
    for (const auto &i : arr)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}