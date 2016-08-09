#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main()
{
	char ch;
	int choice;
	int ret_val = 0;
	struct node *head = NULL;
	int *data = NULL;
	int value = 0;

	while (1) {
		printf("\nMENU\n\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter a value\n");
				scanf("%d", &value);
				data = (int *) malloc (sizeof(int));
				*data = value;
				ret_val = insert_node(&head, (void *)data);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 2:
				ret_val = delete_node(&head);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 3:
				print_list(head);
				break;
			default:
				printf("\nWrong choice. Doing nothing\n");
		}
		printf("Do you want to continue (y/n) ??");
		scanf(" %c", &ch);
		if (ch == 'n' || ch == 'N') {
			printf("\nBreaking the driver loop\n");
			break;
		}
	}
	return 0;
}
