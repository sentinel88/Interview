#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"


/* Print a node in the bst */
static void
print_node (struct node *ptr)
{
        printf("%d-->", *((int *)(ptr->data)));
}


/* Return a node for the bst and initialize its members */
static struct node *
get_bst_node (void *data)
{
	struct node *Node = NULL;

	Node = (struct node *) malloc (sizeof(struct node));
        memset(Node, 0, sizeof(struct node));
        Node->data = data;
        Node->left = NULL;
	Node->right = NULL;

	return Node;
}


/* Insert a node in the bst */
extern int
insert (struct node **head, void *data)
{
	printf("\nInside insert function\n");

	struct node *ptr = NULL;
	int value = 0;
	int input = *(int *)(data);

	ptr = *head;
	while (ptr) {
		value = *(int *)(ptr->data);
		if (input <= value)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	ptr = get_bst_node(data);
	printf("\nExiting insert function\n");

	return 0;
}


/* Delete a node from the bst */
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


/* Inorder traversal of the bst */
extern void 
inorder (struct node *head)
{
	printf("\nInside inorder function\n");

	if (head == NULL) {
		return;
	} 
	while (head) {
		inorder(head->left);
		print_node(head);
		inorder(head->right);	
	}

	printf("\nExiting inorder function\n");	
}


/* Preorder traversal of the bst */
extern void
preorder (struct node *head)
{
	printf("\nInside preorder function\n");

        if (head == NULL) {
                return;
        }
        while (head) {
                print_node(head);
                preorder(head->left);
                preorder(head->right);
        }

        printf("\nExiting preorder function\n");
}


/* Postorder traversal of the bst */
extern void
postorder (struct node *head)
{
	printf("\nInside postorder function\n");

        if (head == NULL) {
                return;
        }
        while (head) {
                postorder(head->left);
                postorder(head->right);
                print_node(head);
        }

        printf("\nExiting postorder function\n");
}
