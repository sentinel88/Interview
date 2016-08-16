#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "company.h"
#include "employee.h"
using namespace std;

int main()
{
	Company cObj;
	Employee eObj;
	int choice;
	char ch;
	std::string Name;
	int Id;
	
	while(1) {
		cout <<"\nMENU\n\n";
		cout <<"1. Add Employee\n";
                cout <<"2. Remove Employee\n";
                cout <<"3. Display Payroll\n";
                cout <<"\nEnter your choice\n";
                cin >>choice;
                switch(choice)
                {
                        case 1:
                                cout << "\nEnter the name of the employee\n";
                                cin >> Name;
				eObj.setName(Name);
				cout << "\nEnter the employee id\n";
				cin >> Id;
				eObj.setId(Id);
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
	return 0;
}
