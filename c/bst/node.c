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
	struct node *prev = NULL;
	int value = 0;
	int input = *(int *)(data);

	if (*head == NULL) {
		*head = get_bst_node(data);
		return 0;
	}
	ptr = *head;
	while (ptr) {
		prev = ptr;
		value = *(int *)(ptr->data);
		if (input <= value)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	if (input <= value)
		prev->left = get_bst_node(data);
	else
		prev->right = get_bst_node(data);

	printf("\nExiting insert function\n");
	return 0;
}


/* Delete a node from the bst */
extern int
delete_node (struct node **head, void *data)
{
	printf("\nEntering delete node function\n");

	struct node *ptr = NULL;

	if (*head == NULL) {
		printf("\nEmpty list\n");
	} else {
		printf("\nDeleting the node\n");
	}

	printf("\nExiting delete node function\n");
	return 0;
}


/* Inorder traversal of the bst */
extern void 
inorder (struct node *head)
{
	if (head == NULL) {
		return;
	} 
	inorder(head->left);
	print_node(head);
	inorder(head->right);	
}


/* Preorder traversal of the bst */
extern void
preorder (struct node *head)
{
        if (head == NULL) {
                return;
        }
	print_node(head);
	preorder(head->left);
	preorder(head->right);
}


/* Postorder traversal of the bst */
extern void
postorder (struct node *head)
{
        if (head == NULL) {
                return;
        }
	postorder(head->left);
	postorder(head->right);
	print_node(head);
}
