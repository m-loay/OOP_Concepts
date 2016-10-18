/*
 * main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: modys
 */

#include <iostream>
#include<iomanip>
#include<vector>
#include "employee.h"
#include "CommissionEmployee.h"
#include "BasePlus.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
using namespace std;


void virtualPointer (const employee* const);
void virtualRef(const employee &);
int main ()
{
	SalariedEmployee salEmp("Mody", "Ali","11-111",5000);
	HourlyEmployee hlEmp("Maha", "Imam","22-222", 16.5, 40);
	CommissionEmployee comEmp("Nouran", "osama","33-333",10000,0.06);
	BasePlus baseEmp ("Rof", "karam", "444-444",5000,0.04,300);

	cout<<"Priniting data using objects"<<endl;
	salEmp.print();
	cout<<"earned: "<<salEmp.earnings();

	hlEmp.print();
	cout<<"earned: "<<hlEmp.earnings();

	comEmp.print();
	cout<<"earned: "<<comEmp.earnings();

	baseEmp.print();
	cout<<"earned: "<<baseEmp.earnings();

	vector <employee *> employee(4);

	employee[0]=&salEmp;
	employee[1]=&hlEmp;
	employee[2]=&comEmp;
	employee[3]=&baseEmp;

	cout << "Employees processed polymorphically via dynamic binding:\n\n";
	cout << "Virtual function calls made off base-class pointers:\n\n";

	for (size_t i=0; i<employee.size(); i++)
	{
		virtualPointer(employee[i]);
	}

	for (size_t i=0; i<employee.size(); i++)
	{
		virtualRef(*employee[i]);
	}
}

void virtualPointer (const employee* const baseCalssPtr)
{
	baseCalssPtr->print();
	cout<<"\nearned: "<<baseCalssPtr->earnings();
}

void virtualRef (const employee &baseClassRef)
{
	baseClassRef.print();
	cout<<"\nearned: "<<baseClassRef.earnings();
}
