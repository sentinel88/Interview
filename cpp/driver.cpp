#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "company.h"
#include "employee.h"
using namespace std;


static Employee*
get_new_employee(int inType)
{
	Employee *ptr = NULL;

        if (!inType)
                ptr = new PermanentEmployee();
        else
                ptr = new ContractEmployee();

	return ptr;
}


int main()
{
	Company cObj("TUM", "Munich");
	Employee *eObj = NULL;
	Company *dupObj = NULL;
	int choice;
	char ch;
	std::string Name;
	std::string empString;
	int Id;
	int Type;
	
	while(1) {
		cout <<"\nMENU\n\n";
		cout <<"1. Add Employee\n";
                cout <<"2. Remove Employee\n";
                cout <<"3. Display Payroll\n";
		cout <<"4. Duplicate the Company and Display its payroll\n";
                cout <<"\nEnter your choice\n";
                cin >>choice;
                switch(choice)
                {
                        case 1:
                                cout << "\nEnter the name of the employee\n";
                                cin >> Name;
				cout << "\nEnter the employee id\n";
				cin >> Id;
				cout << "\nEnter the type of the employee\n";
				cin >> Type;
				eObj = get_new_employee(Type);
				eObj->setName(Name);
				eObj->setId(Id);
				eObj->setType(Type);
				if (Type) {
					cout << "Enter the agency of this contract employee\n";
					cin >>empString;
					(static_cast<ContractEmployee*>(eObj))->setAgency(empString);
				} else {
					cout << "Enter the department of this permanent employee\n";
					cin >>empString;
					(static_cast<PermanentEmployee*>(eObj))->setDept(empString);
				}
                                //cObj.addEmployee(eObj);
				cObj = cObj + eObj;
                                break;
                        case 2:
				cout << "Enter the id of the employee who should be removed\n";
				cin >> Id;
                                //cObj.deleteEmployee(Id);
				cObj = cObj - Id;
                                break;
                        case 3:
				cout <<cObj;
                                break;
			case 4: 
				dupObj = new Company(cObj);
				cout <<*dupObj;
				break;
                        default:
                                cout << "\nWrong choice. Doing nothing\n";
                }
                cout <<"Do you want to continue (y/n) ??";
                cin >>ch;
                if (ch == 'n' || ch == 'N') {
                        cout << "\nBreaking the driver loop\n";
                        break;
                }
        }
	if (dupObj)
		delete dupObj;
	if (eObj)
		delete eObj;
	return 0;
}
