#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "company.h"
#include "employee.h"

int main()
{
	Company cObj;
	Employee eObj;
	int choice;
	char ch;
	
	while(1) {
		cout <<"\nMENU\n\n";
		cout <<"1. Add\n";
                cout <<"2. Delete\n";
                cout <<"3. Display\n";
                cout <<"\nEnter your choice\n";
                cin >>choice;
                switch(choice)
                {
                        case 1:
                                cout <<"\nEnter a value\n";
                                cin("%d", &value);
                                data = (int *) malloc (sizeof(int));
                                *data = value;
                                ret_val = insert_node(&head, (void *)data);
                                if (ret_val)
                                        cout("\nOperation failed\n");
                                break;
                        case 2:
                                ret_val = delete_node(&head);
                                if (ret_val)
                                        cout("\nOperation failed\n");
                                break;
                        case 3:
				cObj.display();
                                break;
                        default:
                                cout("\nWrong choice. Doing nothing\n");
                }
                cout <<"Do you want to continue (y/n) ??";
                cin >>ch;
                if (ch == 'n' || ch == 'N') {
                        cout("\nBreaking the driver loop\n");
                        break;
                }
        }
        return 0;
}
