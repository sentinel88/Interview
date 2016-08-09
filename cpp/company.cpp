#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "company.h"


Company::Company()
{
	cout << "Inside default constructor" << endl;
	Name = "Unknown";
	Location = "Unknown";
	empCount = -9999;
	Payroll = NULL;
}


Company::Company(string inName, string inLocation, int inCount)
{
	cout << "Inside parameterized constructor" << endl;
	Name = inName;
	Location = inLocation;
	empCount = inCount;
	Payroll = NULL;
}


void 
Company::setName(string inName)
{
	Name = inName;
}


string 
Company::getName() const
{
	return Name;
}


void
Company::setLocation(string inLocation)
{
        Location = inLocation;
}


string
Company::getLocation() const
{
        return Location;
}


void
Company::setCount(int inCount)
{
	empCount = inCount;
}


int
Company::getCount() const
{
	return empCount;
}


void
Company::addEmployee(Employee inEmp)
{
}


void
Company::delEmployee(Employee inEmp)
{
}


void 
Company::display() const
{
}
