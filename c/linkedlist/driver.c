#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


static int *
get_new_node (int *value)
{
	int *data = NULL;

	data = (int *) malloc (sizeof(int));
	*data = *value;
	return data;
}


int main (int argc, char *argv[])
{
	char ch;
	int choice;
	int ret_val = 0;
	struct node *head = NULL;
	int *data = NULL;
	int value = 0;
	int pos = -1;

	while (1) {
		printf("\nMENU\n\n");
		printf("1. Insert at the front\n");
		printf("2. Insert at a position\n");
		printf("3. Delete from the front\n");
		printf("4. Delete from a position\n");
		printf("5. Display\n");
		printf("6. Reverse the linked list\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter a value\n");
				scanf(" %d", &value);
				data = get_new_node(&value);
				ret_val = insert_node(&head, (void *)data);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 2:
				printf("\nEnter the position at which to insert\n");
				scanf(" %d", &pos);
				printf("\nEnter a value\n");
				scanf(" %d", &value);
				data = get_new_node(&value);
				ret_val = insert_node_pos(&head, pos, (void *)data);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 3:
				ret_val = delete_node(&head);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 4:
				printf("\nEnter the position at which to delete\n");
                                scanf(" %d", &pos);
                                ret_val = delete_node_pos(&head, pos);
                                if (ret_val)
                                        printf("\nOperation failed\n");
				break;
			case 5:
				print_list(head);
				break;
			case 6:
				head = reverse(head);	
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
