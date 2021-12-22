/*
 * main.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: modys
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

void VectorIntializationMethods(void);
void VectorLogicalOperations(void);
void VectorModifiers(void);
void Vector2d(void);
// An interval has start time and end time
struct Interval 
{
    int start, end;
};
bool compareInterval(Interval i1, Interval i2);

int main ()
{
    /*******************************************************************************
     *  Initialization of Vectors                                                  *
     *******************************************************************************/
    VectorIntializationMethods();

    /*******************************************************************************
     *  Vector Logical Operations                                                  *
     *******************************************************************************/
    VectorLogicalOperations();

    /*******************************************************************************
     *  Vector Modifiers                                                           *
     *******************************************************************************/
    VectorModifiers();

    /*******************************************************************************
     *  Vector 2D                                                                  *
     *******************************************************************************/
    Vector2d();
}

void VectorIntializationMethods(void)
{
    //1) By using defualt constructor and specify the size to create empty vector
    std::vector<int>integers1(7);
    std::vector<int>integers2;
    integers2.push_back(1);
    integers2.push_back(2);
    integers2.push_back(3);

    std::cout<<"Integers 1 size "<<integers1.size()<<" capacity "<<integers1.capacity()<<std::endl;
    std::cout<<"Integers 1 "<<std::endl;
    for(auto const &x:integers1){std::cout<<x<<" ";};
	std::cout<<std::endl;

    std::cout<<"Integers 2 size "<<integers2.size()<<" capacity "<<integers2.capacity()<<std::endl;
    std::cout<<"Integers 2 "<<std::endl;
    for(auto const &x:integers2){std::cout<<x<<" ";};
	std::cout<<std::endl;

    //2) By using defualt constructor and specify number_of_repetition and element_value
    std::vector<int>integers3(7,1);
    std::vector<int>integers4(10,2);

    std::cout<<"Integers 3 size "<<integers3.size()<<" capacity "<<integers3.capacity()<<std::endl;
    std::cout<<"Integers 3 "<<std::endl;
    for(auto const &x:integers3){std::cout<<x<<" ";};
	std::cout<<std::endl;

    std::cout<<"Integers 4 size "<<integers4.size()<<" capacity "<<integers4.capacity()<<std::endl;
    std::cout<<"Integers 4 "<<std::endl;
    for(auto const &x:integers4){std::cout<<x<<" ";};
	std::cout<<std::endl;

    //3) By using Array
    int array[]{1,2,3,4,5};
    int n = sizeof(array) / sizeof(array[0]);
    std::vector<int>integers5(array, array+n);
    std::vector<int>integers6{1,2,3,4,5};


    std::cout<<"Integers 5 size "<<integers5.size()<<" capacity "<<integers5.capacity()<<std::endl;
    std::cout<<"Integers 5 "<<std::endl;
    for(auto const &x:integers5){std::cout<<x<<" ";};
	std::cout<<std::endl;

    std::cout<<"Integers 6 size "<<integers6.size()<<" capacity "<<integers6.capacity()<<std::endl;
    std::cout<<"Integers 6 "<<std::endl;
    for(auto const &x:integers6){std::cout<<x<<" ";};
	std::cout<<std::endl;

    //4 By using another vector (Copy Constructor)
    std::vector<int> vect1{ 10, 20, 30 };
    std::vector<int>integers7(vect1.begin(), vect1.end());
    std::cout<<"Integers 7 size "<<integers7.size()<<" capacity "<<integers7.capacity()<<std::endl;
    std::cout<<"Integers 7 "<<std::endl;
    for(auto const &x:integers7){std::cout<<x<<" ";};
	std::cout<<std::endl;

    std::vector<int> integers8(vect1);
    std::cout<<"Integers 8 size "<<integers8.size()<<" capacity "<<integers8.capacity()<<std::endl;
    std::cout<<"Integers 8 "<<std::endl;
    for(auto const &x:integers8){std::cout<<x<<" ";};
	std::cout<<std::endl;
}

void VectorLogicalOperations(void)
{
    std::vector<int> v1{1,2,3,4,5,6};
    std::vector<int> v2(6,1);
    std::cout<<"v1  size "<<v1.size()<<" capacity "<<v1.capacity()<<std::endl;
    std::cout<<"v2 size "<<v2.size()<<" capacity "<<v2.capacity()<<std::endl;
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;

    // use inequality (!=) operator with vector objects
    std::cout << "\nEvaluating: v1 != v2" << std::endl;
    if (v1 != v2)
    	std::cout <<"integers 1 and integers 2 are not equal "<<std::endl;


    // make v1 = v2
    std::cout << "\n make: v2 = v1" << std::endl;
    v2 = v1;

    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;

    if (v1 != v2)
    	std::cout <<"v1 and v2 are not equal "<<std::endl;
    else
    	std::cout << "v1 and v2 are equals "<<std::endl;

}

void VectorModifiers(void)
{
    std::vector<int> v1{1,2,3,4,5,6};
    std::cout<<"v1  size "<<v1.size()<<" capacity "<<v1.capacity()<<std::endl;
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout << "\nAssign the 1st 4 elements to v2" << std::endl;
    std::vector<int> v2;
    v2.assign(v1.begin(),v1.begin()+4);
    std::cout<<"v2  size "<<v2.size()<<" capacity "<<v2.capacity()<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout << "\nInsert 10 at begnining v2" << std::endl;
    v2.insert(v2.begin(), 10);
    std::cout<<"v2  size "<<v2.size()<<" capacity "<<v2.capacity()<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout << "\nSwap v1 and v2" << std::endl;
    v2.swap(v1);
    std::cout<<"v1  size "<<v1.size()<<" capacity "<<v1.capacity()<<std::endl;
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;
    std::cout<<"v2  size "<<v2.size()<<" capacity "<<v2.capacity()<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout << "\nErase first element of v1" << std::endl;
    v1.erase(v1.begin());
    std::cout<<"v1  size "<<v1.size()<<" capacity "<<v1.capacity()<<std::endl;
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout << "\nclear v1" << std::endl;
    v1.clear();
    std::cout<<"v1  size "<<v1.size()<<" capacity "<<v1.capacity()<<std::endl;
    for(auto const &x:v1){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout << "\npop back v2" << std::endl;
    v2.pop_back();
    std::cout<<"v2  size "<<v2.size()<<" capacity "<<v2.capacity()<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;

    std::cout << "\nchange some elements in v2 using v2.at()" << std::endl;
    v2.at(0) = 3;
    v2.at(4) = -35;
    v2.at(2) = 1000;
    std::cout<<"v2  size "<<v2.size()<<" capacity "<<v2.capacity()<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;


    std::cout << "\nsort v2" << std::endl;
    std::sort(v2.begin(), v2.end());
    std::cout<<"v2  size "<<v2.size()<<" capacity "<<v2.capacity()<<std::endl;
    for(auto const &x:v2){std::cout<<x<<" ";};
    std::cout<<std::endl;



    std::vector<Interval> v { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    std::cout<<"v  size "<<v.size()<<" capacity "<<v.capacity()<<std::endl;
    for (auto x : v)  std::cout << "[" << x.start << ", " << x.end << "] ";
    std::cout << "\nsort Intervals" << std::endl;
    std::sort(v.begin(), v.end(), compareInterval);
    for (auto x : v)  std::cout << "[" << x.start << ", " << x.end << "] ";
    std::cout<<std::endl;
}

void Vector2d(void)
{
    int n = 3;
    int m = 4;
 
    std::vector<std::vector<int>> vec( n, std::vector<int> (m, 1));
    std::cout<<"\n\n\nvec 2d  size "<<vec.size()<<" capacity "<<vec.capacity()<<std::endl;
    std::cout<<"vec 2d "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout<< std::endl;
    }    
}

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}