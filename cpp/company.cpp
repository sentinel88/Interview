#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "company.h"
using namespace std;

int Company::empCount;
//static int global_list_size = _INIT_SIZE;

/*
void
Company::_create_NewEmployee(Employee **ptr,
		 	//const Employee& inEmp, int inType)
		 	Employee *inEmp, int inType)
{
	cout <<"\nInside create new employee\n";
//	cout <<inEmp <<"\n" <<inType;
	cout <<inType <<"\n";
	if (!inType) {
		cout <<"Inside if intype = 0\n";
        	*ptr = new PermanentEmployee(static_cast<const PermanentEmployee&>(*inEmp));
	} else {
		cout <<"Inside if intype = 1\n";
                *ptr = new ContractEmployee(static_cast<const ContractEmployee&>(*inEmp));
	}
}
*/

Company::Company() :
	Name("Unknown"), Location("Unknown")
{
	cout << "Inside default constructor" << endl;
#ifdef DONT_INCLUDE
	Name = "Unknown";
	Location = "Unknown";
	empCount = 0;
#endif
	empCount = 0;
	//Payroll = new Employee*[_INIT_SIZE];
}


Company::Company(const string& inName, const string& inLocation) :
	Name(inName), Location(inLocation)
{
	cout << "Inside parameterized constructor" << endl;
#ifdef DONT_INCLUDE
	Name = inName;
	Location = inLocation;
	empCount = 0;
#endif
	empCount = 0;
	//Payroll = new Employee*[_INIT_SIZE];
}


Company::Company(const Company &inComp) :
	Name(inComp.Name), Location(inComp.Location)
{
	int i = 0;	
	Employee *ptr = NULL;

	cout <<"This is the copy constructor for company class\n";
/*
	Payroll = new Employee*[global_list_size]; */
	list<Employee *>::const_iterator iter = (inComp.Payroll).begin();
	for (i = 0; i < inComp.empCount; i++) {
		//_create_NewEmployee(&Payroll[i], inComp.Payroll[i], (inComp.Payroll[i])->getType());
		//if (inComp.Payroll[i]->getType()) {
		if ((*iter)->getType()) {
			//ptr = new ContractEmployee(inComp.Payroll[i]);
			ptr = new ContractEmployee(*(static_cast<ContractEmployee *>(*iter)));
			Payroll.push_back(ptr);
		} else {
			//ptr = new PermanentEmployee(inComp.Payroll[i]);
			ptr = new PermanentEmployee(*(static_cast<PermanentEmployee *>(*iter)));
			Payroll.push_back(ptr);
		}
		//*Payroll[i] = *(inComp.Payroll[i]);
		*ptr = *(*iter);
		++iter;
	}
}


Company::~Company()
{
	int i = 0;
	Employee *ptr = NULL;
	//ostream output;

	cout << "Deleting the company and all its employee entries\n";

	if (empCount) {
		for (list<Employee *>::iterator iter = Payroll.begin(); 
			iter != Payroll.end(); ++iter) {
			cout <<"Deleting the employee entry\n";
		//for (i = 0; i < empCount; i++) {
                	//delete Payroll[i];
			ptr = *iter;
			//delete ptr;
			//delete *iter;
			iter = Payroll.erase(iter);
			//delete ptr;
        	}
		//delete [] Payroll;
		//delete Payroll;
	}
	cout <<"Finished deleting the company\n";

}


void 
Company::setName(const string& inName)
{
	Name = inName;
}


const string&
Company::getName() const
{
	return Name;
}


void
Company::setLocation(const string& inLocation)
{
        Location = inLocation;
}


const string&
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
//Company::addEmployee(const Employee &inEmp)
Company::addEmployee(Employee *inEmp)
{
	//Employee **newPayroll = NULL;	
	//int i;

	empCount++;
/*
	if (empCount > global_list_size) {
		newPayroll = new Employee*[global_list_size + _INIT_SIZE];
		for (i = 0; i < (empCount - 1); i++) {
			//newPayroll[i] = Payroll[i];
			_create_NewEmployee(&newPayroll[i], Payroll[i], Payroll[i]->getType());
		}	
		for (i = 0; i < (empCount - 1); i++) {
                        delete Payroll[i];
                }
		//delete [] Payroll;
		delete Payroll;
		Payroll = newPayroll;
		global_list_size += _INIT_SIZE;
	} 
	//Payroll[empCount - 1] = inEmp;
	_create_NewEmployee(&Payroll[empCount - 1], inEmp, inEmp->getType());
*/
	Payroll.push_back(inEmp);
}


void
Company::deleteEmployee(int inId)
{
	int i = 0;
	//Employee **ptr = Payroll;
	bool found = false;
	//Employee *ptr = NULL;

	if (empCount == 0) {
		cout << "No employees in the company to remove " << endl;
		return;
	}
	/* for (i = 0; i < empCount; i++) {
		if (inId == ptr[i]->getId()) {
			cout << "Employee with ID: " << inId << "found. Deleting the entry" << endl;
			ptr[i]->setName("Unkown");
			ptr[i]->setId(0);
			//empCount--;
			found = true;
		}
	} */
	//for (auto iter = begin (Payroll); iter != end (Payroll); ++iter) {
	for (std::list<Employee *>::iterator iter = Payroll.begin(); iter != Payroll.end(); ++iter) {
		cout <<"Inside the for loop\n";
		if (inId == (*iter)->getId()) {
			cout << "Employee with ID: " << inId << "found. Deleting the entry" << endl;
                        empCount--;
                        found = true;
			//ptr = *iter;
			//delete *iter;
			iter = Payroll.erase(iter);
			//break;
			//delete ptr;
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
	//Employee **ptr = Payroll;

	cout << "Company: " << getName() << endl;
	cout << "Location: " << getLocation() << endl;
	cout << "EmpCount: " << empCount << endl;
	cout << "Payroll: " << endl << endl;
	if (empCount == 0) {
		cout << "No employees in the company " << endl;
		return;
	}
/*
	for (i = 0; i < empCount; i++) {
		cout << "EmpName: " << ptr[i]->getName() << endl;
		cout << "EmpId: " << ptr[i]->getId() << endl << endl << endl;
	}
*/
	for (const Employee *emp : Payroll) {
		cout << "EmpName: " << emp->getName() << endl;
                cout << "EmpId: " << emp->getId() << endl << endl << endl;
	}
}


Company&
//Company::operator+(const Employee &inEmp)
Company::operator+(Employee *inEmp)
{
	addEmployee(inEmp);
	return *this;
}


Company&
Company::operator-(int inId)
{
	deleteEmployee(inId);
	return *this;
}


ostream&
operator<<(ostream& output, const Company& inComp)
{
	int i = 0;
        //Employee **ptr = inComp.Payroll;

        output << "Company: " << inComp.getName() << endl;
        output << "Location: " << inComp.getLocation() << endl;
        output << "EmpCount: " << inComp.empCount << endl;
        output << "Payroll: " << endl << endl;
        if (inComp.empCount == 0) {
                output << "No employees in the company " << endl;
                return output;
        }
        /*for (i = 0; i < inComp.empCount; i++) {
		if (ptr[i]->getType()) {
			cout << "This is a contract employee being displayed\n";
			output << static_cast<ContractEmployee*>(ptr[i]);
		} else {
			cout << "This is a permanent employee being displayed\n";
			output << static_cast<PermanentEmployee*>(ptr[i]);
		}
        }*/
	for (const Employee *emp : inComp.Payroll) {
		if (emp->getType()) {
                        cout << "This is a contract employee being displayed\n";
                        output << static_cast<const ContractEmployee *>(emp);
                } else {
                        cout << "This is a permanent employee being displayed\n";
                        output << static_cast<const PermanentEmployee *>(emp);
                }
        }
	return output;
}
