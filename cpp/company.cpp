#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "company.h"

int Company::empCount;
int global_list_size = _INIT_SIZE;


Company::Company()
{
	cout << "Inside default constructor" << endl;
	Name = "Unknown";
	Location = "Unknown";
	empCount = 0;
	Payroll = NULL;
}


Company::Company(string inName, string inLocation)
{
	cout << "Inside parameterized constructor" << endl;
	Name = inName;
	Location = inLocation;
	empCount = 0;
	Payroll = NULL;
}


Company::~Company()
{
	cout << "Deleting the company and all its employee entries";
	if (Payroll != NULL)
		delete [] Payroll;
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


int
Company::getCount() const
{
	return empCount;
}


void
Company::addEmployee(Employee inEmp)
{
	empCount++;
}


void
Company::delEmployee(int inId)
{
	int i = 0;
	Employee *ptr = payroll;

	if (empCount == 0) {
		cout << "No employees in the company to remove " << endl;
		return;
	}
	for (i = 0; i < empCount; i++) {
		if (inId == ptr[i]->empId) {
			cout << "Employee with ID: " << inId << "found. Deleting the entry" << endl;
			ptr[i]->Name = "Unknown";
			ptr[i]->empId = 0;
			empCount--;
		}
	}
}


void 
Company::display() const
{
	int i = 0;
	Employee *ptr = Payroll;

	cout << "Company: " << Name << endl;
	cout << "Location: " << Location << endl;
	cout << "EmpCount: " << empCount << endl;
	cout << "Payroll: " << endl << endl;
	if (empCount == 0) {
		cout << "No employees in the company " << endl;
		return;
	}
	for (i = 0; i < empCount; i++) {
		cout << "EmpName: " << ptr[i]->empName << endl;
		cout << "EmpId: " << ptr[i]->empId << endl << endl << endl;
	}
}
