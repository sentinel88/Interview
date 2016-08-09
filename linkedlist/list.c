#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"


/* Print a node in the linked list */
static void
print_node (struct node *ptr)
{
	printf("%d-->", *((int *)(ptr->data)));
}

/* Insertion at the front of the list */
extern int
insert_node (struct node **head, void *data)
{
	printf("\nInside insert node function\n");

	struct node *ptr = NULL;

	ptr = (struct node *) malloc (sizeof(struct node));
	memset(ptr, 0, sizeof(struct node));
	ptr->data = data;
	ptr->next = NULL;
	if (*head == NULL) {
		*head = ptr;
	} else {
		ptr->next = *head;
		*head = ptr;
	}

	printf("\nExiting insert node function\n");
	return 0;	
}

/* Deletion from the front of the list */
extern int
delete_node (struct node **head)
{
	printf("\nEntering delete node function\n");

	struct node *ptr = NULL;

	if (*head == NULL) {
		printf("\nEmpty list\n");
	} else {
		ptr = *head;
		*head = (*head)->next;
		free((int *)(ptr->data));
		free(ptr);
	}

	printf("\nExiting delete node function\n");
	return 0;
}

/* Print the linked list */
extern void 
print_list (struct node *head)
{
	printf("\nInside print list function\n");

	struct node *ptr = NULL;
	
	if (head == NULL) {
		printf("\nEmpty list\n");
	} else {
		ptr = head;
		while (ptr) {
			print_node(ptr);
			ptr = ptr->next;
		}
	}

	printf("\nExiting print list function\n");	
}
