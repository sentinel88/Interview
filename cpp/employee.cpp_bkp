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
	salary = 500;
}


Employee::Employee(const string& inName, int inId) :
	Name(inName), empId(inId)
{
	cout << "Inside parameterized constructor" << endl;
	salary = 500;
	//Name = inName;
	//empId = inId;
}


Employee::Employee(const Employee &inEmp) :
	Name(inEmp.Name), empId(inEmp.empId)
{
	cout <<"This is the copy constructor for the employee class\n";
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
Employee::setType(int inType)
{
        Type = inType;
}


int
Employee::getType() const
{
        return Type;
}


void
Employee::print() const
{
	cout << "Name: " << Name <<endl;
	cout << "Id: " << empId <<endl;
	cout << "Salary: " <<salary <<endl;
}


Employee&
Employee::operator=(const Employee &inEmp)
{
	if (this == &inEmp) {
		cout <<"Same objects in the assignment statement hence nothing will be done";
		return *this;
	}
	Name = inEmp.Name;
	empId = inEmp.empId;
	return *this;
}


void
Employee::incSalary()
{
	cout <<"In the function increase salary\n";
	if (!Type)
		salary = salary + 500;
	else
		salary = salary + 200;
}


ostream&
operator<<(ostream& output, const Employee *inEmployee)
{
	output << "Name: " << inEmployee->Name <<endl;
	output << "Id: " << inEmployee->empId <<endl;
	output << "Salary: " << inEmployee->salary <<endl;
	return output;
}


PermanentEmployee::PermanentEmployee() :
	Dept("Unknown")
{
	cout <<"This is the default constructor for the Permanent Employee\n";
}


PermanentEmployee::PermanentEmployee(const string& inName, 
					int Id, const string& inDept) :
			Employee(inName, Id), Dept(inDept)
{
	cout <<"This is the parameterized constructor of the permanent employee class\n";
}


PermanentEmployee::PermanentEmployee(const PermanentEmployee& inEmp) :
			Employee(inEmp), Dept(inEmp.Dept)
{
	cout <<"This is the copy constructor for permanent employee class\n";
}


PermanentEmployee::~PermanentEmployee()
{
	cout <<"This is the destructor for permanent employee class\n";
}


void
PermanentEmployee::setDept(const string& inDept)
{
        Dept = inDept;
}


const string&
PermanentEmployee::getDept() const
{
        return Dept;
}


void
PermanentEmployee::incSalary()
{
	cout <<"Salary increment function for a permanent employee\n";
	//salary = salary + 500;
	Employee::incSalary();
}


ostream&
operator<<(ostream& output, const PermanentEmployee *inEmployee)
{
        //output << "Name: " << inEmployee->Name <<endl;
        //output << "Id: " << inEmployee->empId <<endl;
	cout << "Inside the output function for permanent employee\n";
	output << static_cast<const Employee*>(inEmployee);
	cout << "Reached here\n";
	output << "Dept: " <<inEmployee->Dept <<endl;
        return output;
}


ContractEmployee::ContractEmployee() :
        Agency("Unknown")
{
        cout <<"This is the default constructor for the Contract Employee\n";
}


ContractEmployee::ContractEmployee(const string& inName,
                                        int Id, const string& inAgency) :
                        Employee(inName, Id), Agency(inAgency)
{
        cout <<"This is the parameterized constructor of the contract employee class\n";
}


ContractEmployee::ContractEmployee(const ContractEmployee& inEmp) :
			Employee(inEmp), Agency(inEmp.Agency)
{
        cout <<"This is the copy constructor for contract employee class\n";
}


ContractEmployee::~ContractEmployee()
{
        cout <<"This is the destructor for contract employee class\n";
}


void
ContractEmployee::setAgency(const string& inAgency)
{
        Agency = inAgency;
}


const string&
ContractEmployee::getAgency() const
{
        return Agency;
}


void
ContractEmployee::incSalary()
{
	cout <<"Salary increment function for a contract employee\n";
	//salary = salary + 200;
	Employee::incSalary();
}



ostream&
operator<<(ostream& output, const ContractEmployee *inEmployee)
{
        //output << "Name: " << inEmployee->Name <<endl;
        //output << "Id: " << inEmployee->empId <<endl;
	cout << "Inside the output function for contract employee\n";
        output << static_cast<const Employee*>(inEmployee);
        output << "Agency: " <<inEmployee->Agency <<endl;
        return output;
}
