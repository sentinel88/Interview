#ifndef _COMP_H
#define _COMP_H
#include "employee.h"
#define _INIT_SIZE 3

class Company
{
	public:
		Company();
		Company(std::string inName, std::string inLocation);	
		~Company();
		void setName(std::string inName);
		std::string getName() const;
		int getCount() const;
		void setLocation(std::string inLocation);
		std::string getLocation() const;
		void addEmployee(Employee inEmp);
		void deleteEmployee(int inId);
		void display() const;	
	private:
		std::string Name;
		std::string Location;
		static int empCount;
		Employee *Payroll;
};

#endif
