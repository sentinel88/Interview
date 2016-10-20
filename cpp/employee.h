#ifndef _EMP_H
#define _EMP_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

template <typename T>
class Employee;

template <typename T>
std::ostream& operator<<(std::ostream& output, const Employee<T> *inEmployee);

template <typename T>
class Employee
{
	public:
		Employee();
		Employee(const std::string &inName, int inId, const T& inSalary);
		Employee(const Employee<T>& inEmp);
		virtual ~Employee();
		void setName(const std::string &inName);
		const std::string& getName() const;
		void setId(int inId);
		int getId() const;
		void setType(int inType);
		int getType() const;
		void print() const;
		virtual void incSalary();
		Employee<T>& operator=(const Employee<T>& inEmp);
		friend std::ostream& operator<<<T>(std::ostream& output, const Employee *inEmployee);
	private:
		std::string Name;
		int empId;
		int Type;
		//int salary;
		T salary;
};

template <typename T>
class PermanentEmployee;

template <typename T>
std::ostream& operator<<(std::ostream& output, const PermanentEmployee<T> *inEmployee);


template <typename T>
class PermanentEmployee : public Employee<T>
{
	public:
		PermanentEmployee();
		PermanentEmployee(const std::string& inName, int Id, const T& inSalary, const std::string& inDept);
		PermanentEmployee(const PermanentEmployee<T>& inEmp);
		virtual ~PermanentEmployee();
		const std::string& getDept() const;
		void setDept(const std::string& inDept);
		void incSalary();
		friend std::ostream& operator<<<T>(std::ostream& output, const PermanentEmployee *inEmployee);
	private:
		std::string Dept;
};


template <typename T>
class ContractEmployee;

template <typename T>
std::ostream& operator<<(std::ostream& output, const ContractEmployee<T> *inEmployee);


template <typename T>
class ContractEmployee : public Employee<T>
{
        public:
                ContractEmployee();
                ContractEmployee(const ContractEmployee<T> &inEmp);
		ContractEmployee(const std::string& inName, int Id, const T& inSalary, const std::string& inAgency);
                virtual ~ContractEmployee();
		const std::string& getAgency() const;
		void setAgency(const std::string& inAgency);
		void incSalary();
		friend std::ostream& operator<<<T>(std::ostream& output, const ContractEmployee *inEmployee);
        private:
                std::string Agency;
};

template <typename T>
Employee<T>::Employee()
{
        cout << "Inside default constructor" << endl;
        Name = "Unknown";
        empId = -9999;
        salary = 500;
}


template <typename T>
Employee<T>::Employee(const string& inName, int inId, const T& inSalary) :
        Name(inName), empId(inId), salary(inSalary)
{
        cout << "Inside parameterized constructor" << endl;
        salary = 500;
        //Name = inName;
        //empId = inId;
}


template <typename T>
Employee<T>::Employee(const Employee<T> &inEmp) :
        Name(inEmp.Name), empId(inEmp.empId)
{
        cout <<"This is the copy constructor for the employee class\n";
}


template <typename T>
Employee<T>::~Employee()
{
        cout <<"Destroying the entry for employee ID: "<< empId << endl;
}


template <typename T>
void 
Employee<T>::setName(const string& inName)
{
        Name = inName;
}


template <typename T>
const string& 
Employee<T>::getName() const
{
        return Name;
}


template <typename T>
void
Employee<T>::setId(int inId)
{
        empId = inId;
}


template <typename T>
int
Employee<T>::getId() const
{
        return empId;
}


template <typename T>
void
Employee<T>::setType(int inType)
{
        Type = inType;
}


template <typename T>
int
Employee<T>::getType() const
{
        return Type;
}


template <typename T>
void
Employee<T>::print() const
{
        cout << "Name: " << Name <<endl;
        cout << "Id: " << empId <<endl;
        cout << "Salary: " <<salary <<endl;
}


template <typename T>
Employee<T>&
Employee<T>::operator=(const Employee<T> &inEmp)
{
        if (this == &inEmp) {
                cout <<"Same objects in the assignment statement hence nothing will be done";
                return *this;
        }
        Name = inEmp.Name;
        empId = inEmp.empId;
        return *this;
}


template <typename T>
void
Employee<T>::incSalary()
{
        cout <<"In the function increase salary\n";
        if (!Type)
                salary = salary + 500;
        else
                salary = salary + 200;
}


template <typename T>
ostream&
operator<<(ostream& output, const Employee<T> *inEmployee)
{
        output << "Name: " << inEmployee->Name <<endl;
        output << "Id: " << inEmployee->empId <<endl;
        output << "Salary: " << inEmployee->salary <<endl;
        return output;
}


template <typename T>
PermanentEmployee<T>::PermanentEmployee() :
        Dept("Unknown")
{
        cout <<"This is the default constructor for the Permanent Employee\n";
}


template <typename T>
PermanentEmployee<T>::PermanentEmployee(const string& inName, int Id,
                                        const T& inSalary, const string& inDept) :
                        Employee<T>(inName, Id, inSalary), Dept(inDept)
{
        cout <<"This is the parameterized constructor of the permanent employee class\n";
}


template <typename T>
PermanentEmployee<T>::PermanentEmployee(const PermanentEmployee<T>& inEmp) :
                        Employee<T>(inEmp), Dept(inEmp.Dept)
{
        cout <<"This is the copy constructor for permanent employee class\n";
}


template <typename T>
PermanentEmployee<T>::~PermanentEmployee()
{
        cout <<"This is the destructor for permanent employee class\n";
}


template <typename T>
void
PermanentEmployee<T>::setDept(const string& inDept)
{
        Dept = inDept;
}



template <typename T>
void
PermanentEmployee<T>::incSalary()
{
        cout <<"Salary increment function for a permanent employee\n";
        //salary = salary + 500;
        Employee<T>::incSalary();
}


template <typename T>
ostream&
operator<<(ostream& output, const PermanentEmployee<T> *inEmployee)
{
        //output << "Name: " << inEmployee->Name <<endl;
        //output << "Id: " << inEmployee->empId <<endl;
        cout << "Inside the output function for permanent employee\n";
        output << static_cast<const Employee<T>*>(inEmployee);
        cout << "Reached here\n";
        output << "Dept: " <<inEmployee->Dept <<endl;
        return output;
}

template <typename T>
ContractEmployee<T>::ContractEmployee() :
        Agency("Unknown")
{
        cout <<"This is the default constructor for the Contract Employee\n";
}


template <typename T>
ContractEmployee<T>::ContractEmployee(const string& inName, int Id,
                                        const T& inSalary, const string& inAgency) :
                        Employee<T>(inName, Id, inSalary), Agency(inAgency)
{
        cout <<"This is the parameterized constructor of the contract employee class\n";
}


template <typename T>
ContractEmployee<T>::ContractEmployee(const ContractEmployee& inEmp) :
                        Employee<T>(inEmp), Agency(inEmp.Agency)
{
        cout <<"This is the copy constructor for contract employee class\n";
}


template <typename T>
ContractEmployee<T>::~ContractEmployee()
{
        cout <<"This is the destructor for contract employee class\n";
}


template <typename T>
void
ContractEmployee<T>::setAgency(const string& inAgency)
{
        Agency = inAgency;
}


template <typename T>
const string&
ContractEmployee<T>::getAgency() const
{
        return Agency;
}


template <typename T>
void
ContractEmployee<T>::incSalary()
{
        cout <<"Salary increment function for a contract employee\n";
        //salary = salary + 200;
        Employee<T>::incSalary();
}



template <typename T>
ostream&
operator<<(ostream& output, const ContractEmployee<T> *inEmployee)
{
        //output << "Name: " << inEmployee->Name <<endl;
        //output << "Id: " << inEmployee->empId <<endl;
        cout << "Inside the output function for contract employee\n";
        output << static_cast<const Employee<T>*>(inEmployee);
        output << "Agency: " <<inEmployee->Agency <<endl;
        return output;
}

#endif
