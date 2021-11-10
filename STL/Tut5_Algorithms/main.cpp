/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: modys
 */
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>


void fillAlgos(void);
void mathAlgos(void);
void searchSortAlgos(void);
int main ()
{
    /*******************************************************************************
     *  Fill & Fill_n                                                              *
     *******************************************************************************/
    fillAlgos();
    
    /*******************************************************************************
     *  Math Algos                                                                 *
     *******************************************************************************/
    mathAlgos();

    /*******************************************************************************
     *  Searching & Sorting Algos                                                                 *
     *******************************************************************************/
    searchSortAlgos();

}

void fillAlgos(void)
{
    std::vector<char> chars(10);
    std::cout<<"chars: "<<std::endl;
    for(auto const &x:chars){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout<<"fill chars: As "<<std::endl;
    std::fill(chars.begin(), chars.end(),'A');
    for(auto const &x:chars){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout<<"fill first 5 elements in chars: Bs "<<std::endl;
    std::fill_n(chars.begin(), 5,'B');
    for(auto const &x:chars){std::cout<<x<<" ";};
    std::cout<<std::endl;
}

void mathAlgos(void)
{
    std::vector<int>v1{2,10,2,-20,2,333,2,34,45,2,};
    std::cout<<"v1: "<<std::endl;
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout<<"get smallest number: "<<std::endl;
    std::cout<<*(std::min_element(v1.begin(), v1.end()))<<std::endl;

    std::cout<<"get biggest number: "<<std::endl;
    std::cout<<*(std::max_element(v1.begin(), v1.end()))<<std::endl;

    int num1(10),num2(-5);
    std::cout<<"num1 = "<<num1<<" num2="<<num2<<std::endl;
    std::cout<<"get min number of num1 and num2: "<<std::endl;
    std::cout<<std::min(num1, num2)<<std::endl;
    std::cout<<"get max number of num1 and num2: "<<std::endl;
    std::cout<<std::max(num1, num2)<<std::endl;


    std::cout<<"get sum: "<<std::endl;
    std::cout<<std::accumulate(v1.begin(), v1.end(),0)<<std::endl;

    std::cout<<"increase all array elements by 1: "<<std::endl;
    std::for_each(v1.begin(), v1.end(),[](int &n){n++;});
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout<<"calculate RMS v1 & v2: "<<std::endl;
    std::vector<int> v2(v1);
    std::vector<int> v3(v1.size());
    std::for_each(v2.begin(), v2.end(),[](int &n){n++;});
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;
    std::transform(v2.begin(), v2.end(), v1.begin(), v3.begin(),[](int x1,int x2){return (x1 - x2)*(x1 - x2);});

    std::cout<<"v3 = (v2 - v1)^2: "<<std::endl;
    for(auto const &x:v3){std::cout<<x<<" ";};
    std::cout<<std::endl;
    std::cout<<"sum(v3): "<<std::endl;
    std::cout<<std::accumulate(v3.begin(), v3.end(),0)<<std::endl;
}

void searchSortAlgos(void)
{
    std::vector<int>v1{2,10,2,-20,2,333,2,34,45,2,};
    std::cout<<"v1: "<<std::endl;
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout<<"find 34: "<<std::endl;
    auto found(std::find(v1.begin(), v1.end(), 2));
    if(found != v1.end())
    {
        std::cout << "Found 34 at found "<<std::endl;
    }
    else
    {
        std::cout << "34 not found"<<std::endl;
    }

    std::cout<<"sort v1: "<<std::endl;
    std::sort(v1.begin(), v1.end());
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout<<"Binary search for 2v1: "<<std::endl;
    if(std::binary_search(v1.begin(), v1.end(), 10))
    {
        std::cout << "13 was found in v";
    }
    else
    {
        std::cout << "13 was not found in v";    
    }

}