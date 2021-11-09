/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: modys
 */
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

typedef std::pair<std::unordered_set<int>::iterator,bool> setIntPair;

void setIntializationMethods(void);
void setModifiers(void);
template <typename T> 
void printSet(const std::unordered_set<T> &refList);

int main ()
{
    /*******************************************************************************
     *  Initialization of Sets                                                     *
     *******************************************************************************/
    setIntializationMethods();

    /*******************************************************************************
     *  Sets Modifiers                                                             *
     *******************************************************************************/
    setModifiers();
}

void setIntializationMethods(void)
{
    //1. direct Initialization
    std::unordered_set<int> s1{ 20, 30, 10 };
    std::cout<<"s1: "<<std::endl;
    printSet(s1);

    //2. using arrays
    int myints[]= {20,-20,60,40,30};
    std::unordered_set<int> s2(myints,myints+5);
    std::cout<<"s2: "<<std::endl;
    printSet(s2);

    //3. default Constructor and insert method
    std::unordered_set<int> s3;
    s3.insert(5);
    s3.insert(10);
    s3.insert(1);
    s3.insert(100);
    std::cout<<"s3: "<<std::endl;
    printSet(s3);

    //set does not accept duplicates
    setIntPair p;
    std::cout<<"Enter duplicate Element to s3: 5 "<<std::endl;
    p = s3.insert(5);
    std::cout<<"element "<<*(p.first)<<(p.second?" was ":" was not ")<<"inserted"<<std::endl;
    printSet(s3);

    std::cout<<"Enter new Element to s3: 6 "<<std::endl;
    p = s3.insert(6);
    std::cout<<"element "<<*(p.first)<<(p.second?" was ":" was not ")<<"inserted"<<std::endl;
    printSet(s3);

}

void setModifiers(void)
{
    
    std::unordered_set<int> s1{ 20, 30, 10 };
    std::cout<<"s1: "<<std::endl;
    printSet(s1);

    
    int myints[]= {20,-20,60,40,30};
    std::unordered_set<int> s2(myints,myints+5);
    std::cout<<"s2: "<<std::endl;
    printSet(s2);

    //1. set clear
    std::cout<<"s1 clear: "<<std::endl;
    s1.clear();
    printSet(s1);

    //2. using erase
    std::cout<<"s2 erase: 40 to end "<<std::endl;
    auto it(s2.find(40));
    s2.erase(it, s2.end());
    printSet(s2);

}

template <typename T>
void printSet(const std::unordered_set<T> &refList)
{
    if(refList.empty())
    {
        std::cout<<"set is empty "<<std::endl;
    }
    else
    {
        for(const auto &x:refList)
        {
            std::cout<<x<<" ";
        }
    }
    std::cout<<std::endl;
}