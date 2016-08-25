#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


static int *
get_new_data (int *value)
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

	while (1) {
		ret_val = 0;
		printf("\nBinary Search Tree\n\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Inorder\n");
		printf("4. Preorder\n");
		printf("5. Postorder\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter an integer\n");
				scanf(" %d", &value);
				data = get_new_data(&value);
				ret_val = insert(&head, (void *)data);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 2:
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 3:
				inorder(head);
				break;
			case 4:
				preorder(head);
				break;
			case 5:
				postorder(head);
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
