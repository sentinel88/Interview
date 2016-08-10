#ifndef _COMP_H
#define _COMP_H
#include "employee.h"
#define _INIT_SIZE 10

class Company
{
	public:
		Company();
		Company(std::string inName, std::string inLocation);	
		~Company();
		void setName(std::string inName);
		std::string getName() const;
		int getCount() const;
		void addEmployee(Employee inEmp);
		int delEmployee(int inId);
		void display() const;	
	private:
		std::string Name;
		std::string Location;
		static int empCount;
		Employee *Payroll;
};

#endif
