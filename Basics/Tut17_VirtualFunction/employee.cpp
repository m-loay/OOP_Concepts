/*
 * employee.cpp
 *
 *  Created on: Jun 24, 2016
 *      Author: modys
 */

#include "employee.h"

employee::employee(const string &first, const string &last, const string &ssn)
:firstName(first),lastName(last),SocialNumber(ssn)
{
	// TODO Auto-generated constructor stub
	cout<<"  employee Constructor  Called"<<endl;

}

employee::~employee() {
	// TODO Auto-generated destructor stub
	cout<<"employee Destructor  Called"<<endl;
}

void employee::setFirstName(const string &first)
{
	firstName=first;
}

string employee::getFirstName() const
{
	return firstName;
}


void employee::setLastName(const string & last)
{
	lastName=last;
}

string employee::getLastName() const
{
	return lastName;
}


void employee::setSocialNumber(const string & ssn)
{
	SocialNumber=ssn;
}

string employee::getSocialNumber() const
{
	return SocialNumber;
}

void employee::print()const
{
	cout<<" Employee: "<<getFirstName()<<' '<<getLastName()
		<<"\nSocial Security Number:"<<getSocialNumber()<<endl;
}
