#ifndef _COMP_H
#define _COMP_H
#include "employee.h"
#include <iostream>
#include <list>
#include <map>
#define _INIT_SIZE 3

class Company
{
	public:
		Company();
		Company(const std::string& inName, const std::string& inLocation);	
		Company(const Company &inComp);
		~Company();
		void setName(const std::string& inName);
		const std::string& getName() const;
		int getCount() const;
		void setLocation(const std::string& inLocation);
		const std::string& getLocation() const;
		//void addEmployee(const Employee &inEmp);
		void addEmployee(Employee<int> *inEmp);
		void deleteEmployee(int inId);
		void display() const;	
		void annualhike();
		//Company& operator+(const Employee &inEmp);
		Company& operator+(Employee<int> *inEmp);
		Company& operator-(int Id);
		friend std::ostream& operator<<(std::ostream& output, const Company& inComp);
	private:
		std::string Name;
		std::string Location;
		static int empCount;
		//Employee **Payroll;
		//std::list<Employee<int> *> Payroll;
		std::map<int, Employee<int> *> Payroll;
		//void _create_NewEmployee(Employee **ptr, const Employee& inEmp, int inType);
		void _create_NewEmployee(Employee<int> **ptr, Employee<int> *inEmp, int inType);
};

#endif
