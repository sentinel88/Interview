#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "employee.h"


Employee::Employee()
{
	cout << "Inside default constructor" << endl;
	Name = "Unknown";
	empId = -9999;
}


Employee::Employee(string inName, int inId)
{
	cout << "Inside parameterized constructor" << endl;
	Name = inName;
	empId = inId;
}


void 
Employee::setName(string inName)
{
	Name = inName;
}


string 
Employee::getName() const
{
	return Name;
}


void
Employee::setId(int inId) 
{
	empId = inId;
}


int
Employee::getId() const
{
	return empId;
}
