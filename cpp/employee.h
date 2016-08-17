#ifndef _EMP_H
#define _EMP_H
#include <iostream>

class Employee
{
	public:
		Employee();
		Employee(const std::string &inName, int inId);
		Employee(const Employee &inEmp);
		~Employee();
		void setName(const std::string &inName);
		const std::string& getName() const;
		void setId(int inId);
		int getId() const;
		void print() const;
		Employee& operator=(const Employee& inEmp);
		friend std::ostream& operator<<(std::ostream& output, const Employee& inEmployee);
	private:
		std::string Name;
		int empId;
};

#endif
