#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "company.h"
using namespace std;

int Company::empCount;
static int global_list_size = _INIT_SIZE;


Company::Company()
{
	cout << "Inside default constructor" << endl;
	Name = "Unknown";
	Location = "Unknown";
	empCount = 0;
	Payroll = new Employee[_INIT_SIZE];
}


Company::Company(string inName, string inLocation)
{
	cout << "Inside parameterized constructor" << endl;
	Name = inName;
	Location = inLocation;
	empCount = 0;
	Payroll = new Employee[_INIT_SIZE];
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
	Employee *newPayroll = NULL;	
	Employee *ptr = Payroll;
	int i;

	if (empCount == global_list_size) {
		cout << "Reached the upper limit for the size of the list. Resizing the list" << endl;
		newPayroll = new Employee[global_list_size + _INIT_SIZE];
		for (i = 0; i < empCount; i++) {
			newPayroll[i] = ptr[i];
		}	
		delete [] Payroll;
		Payroll = newPayroll;
	}
	empCount++;
	Payroll[empCount - 1] = inEmp;
	global_list_size += _INIT_SIZE;
}


void
Company::deleteEmployee(int inId)
{
	int i = 0;
	Employee *ptr = Payroll;
	bool found = false;

	if (empCount == 0) {
		cout << "No employees in the company to remove " << endl;
		return;
	}
	for (i = 0; i < empCount; i++) {
		if (inId == ptr[i].getId()) {
			cout << "Employee with ID: " << inId << "found. Deleting the entry" << endl;
			ptr[i].setName("Unkown");
			ptr[i].setId(0);
			//empCount--;
			found = true;
		}
	}
	if (found == false) {
		cout << "There was no employee with this id found on the payroll\n";
	}
}


void 
Company::display() const
{
	int i = 0;
	Employee *ptr = Payroll;

	cout << "Company: " << getName() << endl;
	cout << "Location: " << getLocation() << endl;
	cout << "EmpCount: " << empCount << endl;
	cout << "Payroll: " << endl << endl;
	if (empCount == 0) {
		cout << "No employees in the company " << endl;
		return;
	}
	for (i = 0; i < empCount; i++) {
		cout << "EmpName: " << ptr[i].getName() << endl;
		cout << "EmpId: " << ptr[i].getId() << endl << endl << endl;
	}
}
