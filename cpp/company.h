#ifndef _COMP_H
#define _COMP_H
#include "employee.h"
#include <iostream>
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
		void addEmployee(const Employee &inEmp);
		void deleteEmployee(int inId);
		void display() const;	
		Company& operator+(const Employee &inEmp);
		Company& operator-(int Id);
		friend std::ostream& operator<<(std::ostream& output, const Company& inComp);
	private:
		std::string Name;
		std::string Location;
		static int empCount;
		Employee *Payroll;
};

#endif
