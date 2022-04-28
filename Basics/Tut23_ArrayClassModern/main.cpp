#include<iostream>
#include <string>
#include "Array.h"
#define OPERATION(x) std::cout << "######### operation: '" << #x << "' ######### " << std::endl; x

int main() 
{
    /*******************************************************************************************************************
     *  Create two arrays and Print them                                                                               *
     ******************************************************************************************************************/
	Array integers1(7); // seven-element Array
	Array integers2; // 10-element Array by default

	// print integers1 & integers2 size and contents
	std::cout   << "Size of Array integers1 is "
                << "\nArray after initialization:\n"
                <<integers1.getSize()<<std::endl
                << integers1;

	std::cout   << "Size of Array integers2 is "
                << "\nArray after initialization:\n"
                <<integers2.getSize()<<std::endl
                << integers2;

     /******************************************************************************************************************
     *  manipulate arrays and Print them                                                                               *
     ******************************************************************************************************************/
    for (int i = 0; i < integers1.getSize(); i++)
    {
        integers1[i] = i;
    }

    for (int i = 0; i < integers2.getSize(); i++)
    {
        integers2[i] = 2*i;
    }

	// print integers1 & integers2 size and contents
	std::cout   << "Size of Array integers1 is "
                << "\nArray after filling with increasing seq:\n"
                <<integers1.getSize()<<std::endl
                << integers1;
    
	std::cout   << "Size of Array integers2 is "
                << "\nArray after filling with increasing seq multi by 2:\n"
                <<integers2.getSize()<<std::endl
                << integers2;

    /******************************************************************************************************************
     *  Create new array integers3 based on integers1 by using copy constructor                                        *
    *******************************************************************************************************************/
    //check copy constructor
    Array integers3(integers1);
	std::cout   << "Size of Array integers3 is "
                <<integers3.getSize()<<std::endl
                << integers3;
	// use overloaded equality (==) operator
	std::cout << "\nEvaluating: integers1 == integers3"<< std::endl;
	if(integers1==integers3)
    {
	    std::cout << "integers1 and integers3 are equal"<< std::endl;
    }
    else
    {
        std::cout << "integers1 and integers3 are not equal"<< std::endl;
    }

    //check = operator
    integers3 = integers2;
	std::cout   << "Size of Array integers3 is "
                <<integers3.getSize()<<std::endl
                << integers3;
	// use overloaded equality (==) operator
	std::cout << "\nEvaluating: integers2 == integers3"<< std::endl;
	if(integers2==integers3)
    {
	    std::cout << "integers2 and integers3 are equal"<< std::endl;
    }
    else
    {
        std::cout << "integers1 and integers3 are not equal"<< std::endl;
    }

    /******************************************************************************************************************
     *  Create integers4 based on integers3 using move Construct                                                       *
    *******************************************************************************************************************/
    Array integers4(std::move(integers3));

    std::cout<< "Size of Array integers3 is "
             <<integers3.getSize()<<std::endl
             << integers3;

    std::cout<< "Size of Array integers4 is "
             <<integers4.getSize()<<std::endl
             << integers4;

    /******************************************************************************************************************
     *  Create integers5 based on integers3 using equal assignment                                                     *
    *******************************************************************************************************************/
    Array integers5 = integers4;

    std::cout<< "Size of Array integers4 is "
             <<integers4.getSize()<<std::endl
             << integers4;

    std::cout<< "Size of Array integers5 is "
             <<integers5.getSize()<<std::endl
             << integers5;

    /******************************************************************************************************************
     *  Create integers6 based on integers5 using equal assignment (move                                               *
    *******************************************************************************************************************/
    Array integers6 = std::move(integers5);

    std::cout<< "Size of Array integers5 is "
             <<integers5.getSize()<<std::endl
             << integers5;

    std::cout<< "Size of Array integers6 is "
             <<integers6.getSize()<<std::endl
             << integers6;

	return 0;
}