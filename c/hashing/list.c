#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"


struct node **hash_table = NULL;

/* Print a node */
static void
print_node (struct node *ptr)
{
	printf("%s-->", (char *)(ptr->data));
}


static struct node *
get_list_node (void *data)
{
	struct node *Node = NULL;

	Node = (struct node *) malloc (sizeof(struct node));
        memset(Node, 0, sizeof(struct node));
        Node->data = data;
        Node->next = NULL;

	return Node;
}


/* Insertion of a word in the table */
extern int
insert_node (struct node **head, void *data)
{
	printf("\nInside insert node function\n");

	struct node *ptr = NULL;

	ptr = get_list_node(data);
	if (*head == NULL) {
		*head = ptr;
	} else {
		ptr->next = *head;
		*head = ptr;
	}

	printf("\nExiting insert node function\n");
	return 0;	
}


/* Deletion of a word if it exists in the table */
extern int
delete_node (struct node **head, char *data)
{
	printf("\nEntering delete node function\n");

	struct node **ptr = NULL;
	bool found = false;

	if (*head == NULL) {
		printf("\nWord not present in the table\n");
	} else {
		ptr = &head[data[0] - 97];
		while (*ptr) {
			if (!strcmp((*ptr)->data, data)) {
				printf("\nWord found. Deleting it.\n");
				free((*ptr)->data);
				free(*ptr);
				found = true;
				break;
			}
			ptr = &((*ptr)->next);
		}
		if (found == false)
			printf("\nWord not found in the table\n");
	}
	printf("\nExiting delete node function\n");

	return 0;
}



/* Print the table */
extern void 
print_list (struct node **head)
{
	printf("\nInside print list function\n");

	struct node *ptr = NULL;
	
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		ptr = head[i];
		if (ptr)
			printf("\n");
		while (ptr) {
			print_node(ptr);
			ptr = ptr->next;
		}
	}

	printf("\nExiting print list function\n");	
}
