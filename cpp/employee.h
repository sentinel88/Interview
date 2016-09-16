#ifndef _EMP_H
#define _EMP_H
#include <iostream>

class Employee
{
	public:
		Employee();
		Employee(const std::string &inName, int inId);
		Employee(const Employee &inEmp);
		virtual ~Employee();
		void setName(const std::string &inName);
		const std::string& getName() const;
		void setId(int inId);
		int getId() const;
		void setType(int inType);
		int getType() const;
		void print() const;
		virtual void incSalary();
		Employee& operator=(const Employee& inEmp);
		friend std::ostream& operator<<(std::ostream& output, const Employee *inEmployee);
	private:
		std::string Name;
		int empId;
		int Type;
		int salary;
};


class PermanentEmployee : public Employee
{
	public:
		PermanentEmployee();
		PermanentEmployee(const std::string& inName, int Id, const std::string& inDept);
		PermanentEmployee(const PermanentEmployee& inEmp);
		virtual ~PermanentEmployee();
		const std::string& getDept() const;
		void setDept(const std::string& inDept);
		void incSalary();
		friend std::ostream& operator<<(std::ostream& output, const PermanentEmployee *inEmployee);
	private:
		std::string Dept;
};


class ContractEmployee : public Employee
{
        public:
                ContractEmployee();
                ContractEmployee(const ContractEmployee &inEmp);
		ContractEmployee(const std::string& inName, int Id, const std::string& inAgency);
                virtual ~ContractEmployee();
		const std::string& getAgency() const;
		void setAgency(const std::string& inAgency);
		void incSalary();
		friend std::ostream& operator<<(std::ostream& output, const ContractEmployee *inEmployee);
        private:
                std::string Agency;
};

#endif
