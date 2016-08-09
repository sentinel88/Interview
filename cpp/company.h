#ifndef _COMP_H
#define _COMP_H
#include "employee.h"


class Company
{
	public:
		Company();
		Company(std::string inName, std::string inLocation, int inCount);
		void setName(std::string inName);
		std::string getName() const;
		void setCount(int inCount);
		int getCount() const;
		void addEmployee(Employee inEmp);
		int delEmployee(int inId);
		void display() const;	
	private:
		std::string Name;
		std::string Location;
		int empCount;
		Employee *Payroll;
};

#endif
