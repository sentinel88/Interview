#ifndef _EMP_H
#define _EMP_H
#include <iostream>

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
		friend std::ostream& operator<<(std::ostream& output, const Employee<T> *inEmployee);
	private:
		std::string Name;
		int empId;
		int Type;
		//int salary;
		T salary;
};


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
		friend std::ostream& operator<<(std::ostream& output, const PermanentEmployee<T> *inEmployee);
	private:
		std::string Dept;
};


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
		friend std::ostream& operator<<(std::ostream& output, const ContractEmployee<T> *inEmployee);
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
Employee<T>::Employee(const string& inName, int inId) :
        Name(inName), empId(inId)
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


#endif
