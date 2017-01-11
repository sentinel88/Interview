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


/* Insertion at the front of the list */
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


/* Insertion at a given position in the list */
extern int
insert_node_pos (struct node **head, int pos, void *data)
{
        printf("\nInside insert node function\n");

        struct node *ptr = NULL;
	struct node *iter = NULL;
	struct node *prev = NULL;
	int count = 0;

	if (pos < 0) {
		printf("\nInvalid position\n");
		return -1;
	}
	if (*head == NULL || pos == 0) {
		printf("\nInsertion at the front\n");
		return (insert_node(head, data));
	}
	ptr = get_list_node(data);
	iter = *head;
	while (iter) {
		if ( (count == pos) && prev) {
			break;
		}
		prev = iter;
		iter = iter->next;
		count++;
	}
	if (count == pos) {
		ptr->next = iter;
		prev->next = ptr;
	} else {
		printf("\nPosition outside the linked list\n");
		return -1;
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


/* Deletion from a given position in the list */
extern int
delete_node_pos (struct node **head, int pos)
{
        printf("\nEntering delete node function\n");

        struct node *ptr = NULL;
        struct node *iter = NULL;
        struct node *prev = NULL;
        int count = 0;

        if (*head == NULL) {
                printf("\nEmpty list\n");
		return -1;
        }
	if (pos < 0) {
                printf("\nInvalid position\n");
                return -1;
        }
        if (pos == 0) {
                printf("\nDeletion at the front\n");
                return (delete_node(head));
        }
	iter = *head;
        while (iter) {
                if ( (count == pos) && prev) {
                        break;
                }
                prev = iter;
                iter = iter->next;
                count++;
        }
        if (count == pos) {
                prev->next = iter->next;
		free((int *)(iter->data));
		free(iter);
        } else {
                printf("\nPosition outside the linked list\n");
                return -1;
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

#ifdef DONT_INCLUDE
/* Recursively reverse the linked list */
extern struct node *
reverse (struct node *ptr)
{
	printf("\nInside the reverse function\n");

	struct node *revhead = NULL;

	if ((ptr == NULL) || (ptr->next == NULL))
		return ptr;
		
	revhead = reverse(ptr->next);
	ptr->next->next = ptr;
	ptr->next = NULL;
	
	return revhead;
}
#endif

/* Reverse the linked list */
extern struct node *
reverse (struct node *ptr)
{
	printf("\nInside the reverse function\n");

	struct node *prevnode = NULL;
	struct node *temp = NULL;

	if (ptr == NULL)
		return ptr;
		
	while (ptr) {
		temp = ptr->next;
		ptr->next = prevnode;
		prevnode = ptr;
		ptr = temp;
	}

	printf("\nExiting the reverse function\n");
	return prevnode;
}


extern void
pairwise_swap(struct node **head)
{
	struct node *ptr = *head;
	struct node *temp = NULL;

	if (*head == NULL)
		return;
	while (ptr) {
		temp = ptr->next;
		if (temp == NULL || temp->next == NULL) 
			break;
		ptr->next = ptr->next->next;
		/* Better optimization is to swap the if else blocks since the current if block will be tested in every iteration even
		   though it gets executed only in the first iteration */
		if (ptr == *head) {
			*head = temp;
			temp->next = ptr;
		} else {
			temp->next = ptr->next->next;
			ptr->next->next = temp;
			ptr = temp;
		}
	}
}


extern void
merge_list (struct node *head1, struct node *head2)
{

	printf("\nInside merge list function\n");
	printf("\nExiting merge list function\n");
}
