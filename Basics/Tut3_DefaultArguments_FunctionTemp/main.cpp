/*
  * main.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: modys
 */

#include <iostream>
#include <cstring>
#include <concepts>
#include "maximum.h"
#include "Boxvol.h"
using namespace std;
int var(3);

template <typename T> T maxmum(T a, T b)
{
	return (a > b)? a:b;
}

//template <typename T> const T& maxmum(const T& a, const T& b)
//{
//	return (a > b)? a:b;
//}

template<>
const char* maxmum<const char*>(const char*  a, const char * b)
{
	return (std::strcmp(a,b)>0)?a:b;

}

// syntax 1
//template <typename N>
//requires std::integral<N>
//N addIntegeral(N a, N b)
//{
//	return a+b;
//}

// syntax 2
//template <std::integral N>
//N addIntegeral(N a, N b)
//{
//	return a+b;
//}

// syntax 3
auto addIntegeral(std::integral auto a, std::integral auto b)
{
	return a+b;
}

int main ()
{
    Box_vol volume_box;
    volume_box.print_volume();

    /*Default Arguments*/

    /*Default Arguments, set without using any input arguments*/
    volume_box.setDim();
    volume_box.print_volume();

    /*Default Arguments, set the first arguments only*/
    volume_box.setDim(10);
    volume_box.print_volume();

    /*Default Arguments , set the first and second arguments*/
    volume_box.setDim(10,5);
    volume_box.print_volume();

    /*Default Arguments ,  set all arguments*/
    volume_box.setDim(10,5,2);
    volume_box.print_volume();

    /*Function Template*/

    /*given to function integers arguments*/
    volume_box.max_valueInt(10,5,2);
    cout << "dBiggest int: "<<volume_box.getBiggestInt() <<endl;// prompt user for data

    /*given to function floats arguments*/
    volume_box.max_valueDouble(10.5,5.3,2.1);
    cout << "dBiggest double: "<<volume_box.getBiggestDouble() <<endl;// prompt user for data

    /*compare between local and global scope*/
    {
        int var(6);
        std::cout<<"Printing var in local scope, var = "<<var<<std::endl;

        std::cout<<"Printing var in global scope ::var= "<<::var<<std::endl;
    }

    //Function Templates(more details)

    /*Test template usage with same types*/
    std::cout<<"========Test template usage with same types======="<<std::endl;
    int intNum1(10);
    int intNum2(20);

    std::string s1{"learn"};
    std::string s2{"C++"};

    double doubleNum1(22.2);
    double doubleNum2(44.4);

    auto res_int = maxmum(intNum1, intNum2);
    std::cout<<"results : "<<res_int<<std::endl;
    auto res_s = maxmum(s1, s2);
    std::cout<<"results : "<<res_s<<std::endl;
    auto res_d = maxmum(doubleNum1, doubleNum2);
    std::cout<<"results : "<<res_d<<std::endl;

    /*Test template usage with different types*/
    std::cout<<"========Test template usage with different types======="<<std::endl;
    //auto res_mix = maxmum(intNum1, doubleNum2); --> compiler error
    auto res_mixD = maxmum<double>(intNum1, doubleNum2);
    auto res_mixI = maxmum<int>(intNum1, doubleNum2);
    std::cout<<"results for explicit double : "<<res_mixD<<std::endl;
    std::cout<<"results for explicit int : "<<res_mixI<<std::endl;

    /*template usage for references*/
    std::cout<<"========template usage for references======="<<std::endl;
    //overload template function T maxmum(T,T)
    //with const T& maxmum(const T&T,const T&T)
    // will confuse compiler and generates compiler error
    auto res_int_ref = maxmum(intNum1, intNum2);
    std::cout<<"results using references : "<<res_int_ref<<std::endl;

    /*template Specialization*/
    std::cout<<"========template usage for Specialization======="<<std::endl;
    // when add implementation const char* maxmum<const char*>(const char*,const char*)
    // The correct out be shown like previous case
    const char * c1{"learn"};
    const char * c2{"C++"};
    auto res_c = maxmum(c1, c2);
    std::cout<<"results using const char * : "<<res_c<<std::endl;


    /*Constrain template parameters using concepts*/
    std::cout<<"========Constrain template parameters using concepts======="<<std::endl;
    auto simI = addIntegeral(intNum1, intNum2);
    std::cout<<"resultsaddIntegeral : "<<simI<<std::endl;

    //auto simD = addIntegeral(doubleNum1, doubleNum2); --> this will generate compiler error.

}

