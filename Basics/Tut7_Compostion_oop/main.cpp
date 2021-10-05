/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include<iostream>
#include "Date.h"
#include "Employee.h"
using namespace std;

void EmployeeNoMemberInitializerClass(void);
void EmployeeWithMemberInitializerClass(void);
void EmployeeWithMemberInitializerREFClass(void);

int main()
{
	EmployeeNoMemberInitializerClass();
	EmployeeWithMemberInitializerClass();
	EmployeeWithMemberInitializerREFClass();
}

void EmployeeNoMemberInitializerClass(void)
{
	std::cout<<"===========EmployeeNoMemberInitializerClass================"<<std::endl;
	std::cout<<"Date Object Construction"<<std::endl;
	Date birth(7,1,1990,1);
	Date hire (10,1,2016,2);

	std::cout<<"============================================================="<<std::endl;
	std::cout<<"Double Init to date objects --> Member Initializer not used --> Copy Constructor calls"<<std::endl;
	{
		EmployeeNoMemberInitializer che ("Mohamed","Loay",birth,hire);
		che.print();
	}

}

void EmployeeWithMemberInitializerClass(void)
{
	std::cout<<"==============EmployeeWithMemberInitializerClass====================="<<std::endl;
	std::cout<<"Date Object Construction"<<std::endl;
	Date birth(7,1,1990,1);
	Date hire (10,1,2016,2);
	std::cout<<"============================================================="<<std::endl;
	std::cout<<"Single Init to date objects --> Member Initializer used --> Copy Constructor calls"<<std::endl;
	{
		EmployeeWithMemberInitializer spe ("Karim","Dahawy",birth,hire);
		spe.print();
	}

}

void EmployeeWithMemberInitializerREFClass(void)
{
	std::cout<<"=======EmployeeWithMemberInitializerREFClass======"<<std::endl;
	std::cout<<"Date Object Construction"<<std::endl;
	Date birth(7,1,1990,1);
	Date hire (10,1,2016,2);
	std::cout<<"============================================================="<<std::endl;
	std::cout<<"Single Init to date objects --> Member Initializer used --> No Copy Constructor calls"<<std::endl;
	{
		EmployeeWithMemberInitializerREF se ("Moataz","Ibrahim",birth,hire);
		se.print();
	}
}