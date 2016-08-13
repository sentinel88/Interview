#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "employee.h"
using namespace std;


Employee::Employee()
{
	cout << "Inside default constructor" << endl;
	Name = "Unknown";
	empId = -9999;
}


Employee::Employee(const string& inName, int inId)
{
	cout << "Inside parameterized constructor" << endl;
	Name = inName;
	empId = inId;
}


Employee::~Employee()
{
	cout <<"Destroying the entry for employee ID: "<< empId << endl;
}


void 
Employee::setName(const string& inName)
{
	Name = inName;
}


const string&
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


void
Employee::print() const
{
	cout << "Name: " << Name <<endl;
	cout << "Id: " << empId <<endl;
}


ostream&
operator<<(ostream& output, const Employee& inEmployee)
{
	output << "Name: " << inEmployee.Name <<endl;
	output << "Id: " << inEmployee.empId <<endl;
	return output;
}
