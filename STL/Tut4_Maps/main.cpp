/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: modys
 */
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iterator>

typedef std::pair<std::unordered_map<int,int>::iterator,bool> mapIntPair;

void mapIntializationMethods(void);
void mapModifiers(void);
template <typename L, typename R> 
void printMap(const std::unordered_map<L,R> &refmap);

int main ()
{
    /*******************************************************************************
     *  Initialization of Maps                                                     *
     *******************************************************************************/
    mapIntializationMethods();

    /*******************************************************************************
     *  Maps Modifiers                                                             *
     *******************************************************************************/
    mapModifiers();
}

void mapIntializationMethods(void)
{
    //1.default constructor
    std::unordered_map<int,int> map1;
    map1[1] = 10;
    map1[4] = 40;
    map1[5] = 50;
    map1[0] = 0;
    map1[10] = 100;
    std::cout<<"map1: "<<std::endl;
    printMap(map1);

    // (2) Using Range constructor
    std::unordered_map <int, int> tempM;
    tempM[1] = 10;
    tempM[2] = 20;
    tempM[3] = 30;
    tempM[4] = 40;
    tempM[5] = 50;
    tempM[6] = 60;
    std::cout<<"tempM: "<<std::endl;
    printMap(tempM);

    std::unordered_map<int, int> map2(tempM);
    std::cout<<"map2: "<<std::endl;
    printMap(map2);

    // 3. Using Initializer list
    std::unordered_map <int, int> map3{{1,2},{3,4},{5,6},{7,8}};
    map3[9] = 10;
    std::cout<<"map3: "<<std::endl;
    printMap(map3);

    //map does not accept duplicate values
    mapIntPair p = map3.insert(std::unordered_map<int,int>::value_type({1,2}));
    std::cout<<"element {"<<p.first->first<<", "<<p.first->second<<"}"
             <<(p.second?" was ":" was not ")<<"inserted"<<std::endl;
}

void mapModifiers(void)
{
   
    std::unordered_map<int,int> map1;
    map1[1] = 10;
    map1[4] = 40;
    map1[5] = 50;
    map1[0] = 0;
    map1[10] = 100;
    std::cout<<"map1: "<<std::endl;
    printMap(map1);


    std::unordered_map <int, int> map2;
    map2[1] = 10;
    map2[2] = 20;
    map2[3] = 30;
    map2[4] = 40;
    map2[5] = 50;
    map2[6] = 60;
    std::cout<<"map2: "<<std::endl;
    printMap(map2);

    //1. set clear
     std::cout<<"map1 clear: "<<std::endl;
     map1.clear();
     printMap(map1);

    //2. using erase
    std::cout<<"map2 erase: 40 to end "<<std::endl;
    auto it(map2.find(4));
    map2.erase(it, map2.end());
    printMap(map2);
}

template <typename L, typename R> 
void printMap(const std::unordered_map<L,R> &refmap)
{
    if(refmap.empty())
    {
        std::cout<<"set is empty "<<std::endl;
    }
    else
    {
        for(const auto &x:refmap)
        {
            std::cout<<"first: "<<x.first<<" second: "<<x.second<<" "<<std::endl;;
        }
    }
    std::cout<<std::endl;
}