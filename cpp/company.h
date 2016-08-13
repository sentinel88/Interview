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
		~Company();
		void setName(const std::string& inName);
		const std::string& getName() const;
		int getCount() const;
		void setLocation(const std::string& inLocation);
		const std::string& getLocation() const;
		void addEmployee(Employee inEmp);
		void deleteEmployee(int inId);
		void display() const;	
		friend std::ostream& operator<<(std::ostream& output, const Company& inCompany);
	private:
		std::string Name;
		std::string Location;
		static int empCount;
		Employee *Payroll;
};

#endif
