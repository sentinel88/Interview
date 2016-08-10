#ifndef _EMP_H
#define _EMP_H
using namespace std;


class Employee
{
	public:
		Employee();
		Employee(std::string inName, int inId);
		~Employee();
		void setName(std::string inName);
		std::string getName() const;
		void setId(int inId);
		int getId() const;
	private:
		std::string Name;
		int empId;
};

#endif
