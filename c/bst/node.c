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


extern void
free_node(struct node *ptr)
{
	free((int *)(ptr->data));
	free(ptr);
}


static struct node*
left_rightmost(struct node *ptr, struct node **parent)
{
	if (ptr->right == NULL) {
		printf("\nRight subtree is empty\n");
		return ptr;
	}
	while(ptr->right) {
		*parent = ptr;
		ptr = ptr->right;
	}
	return ptr;
}


/* Delete a node from the bst */
extern void
delete_node (struct node **head, struct node *parent, int key)
{
	printf("\nEntering delete node function\n");

	struct node *ptr = NULL;
	struct node *prev = parent;
	int value = 0;
	struct node *replace_node = NULL;

	if (*head == NULL) {
		printf("\nEmpty list\n");
		return;
	} 
	ptr = *head;	
	while (ptr) {
                value = *(int *)(ptr->data);
		if (key == value)
			break;
                prev = ptr;
                if (key < value)
                        ptr = ptr->left;
                else
                        ptr = ptr->right;
        }
        if (key == value) {
		printf("\nNode with the given element found. Deleting this node and adjusting the bst\n");
		if (ptr->left == NULL && ptr->right == NULL) {
			printf("\nDeleting leaf node\n");
			if (prev == NULL)
				*head = NULL;
			if (prev && prev->right == ptr)
				prev->right = NULL;
			if (prev && prev->left == ptr)
				prev->left = NULL;
			free_node(ptr);
		} else if (ptr->left == NULL) {
			printf("\nDeleting a node with right subtree. Connecting prev ptr with the root of its right subtree\n");
			if (prev == NULL)
				*head = ptr->right;
			else {
				if (prev->right == ptr)
					prev->right = ptr->right;
				else
					prev->left = ptr->right;
			}
			free_node(ptr);
		} else if (ptr->right == NULL) {
			printf("\nDeleting a node with left subtree. Connecting prev ptr with the root of its left subtree\n");
			if (prev == NULL)
				*head = ptr->left;
			else {
				if (prev->right == ptr)
					prev->right = ptr->left;
				else
					prev->left = ptr->left;
			}
			free_node(ptr);
                } else {
			printf("\nDeleting a node with both right and left subtrees. Replacing it by a successor from the left subtree\n");
			prev = ptr;
			replace_node = left_rightmost(ptr->left, &prev);
			*(int *)(ptr->data) = *(int *)(replace_node->data);
			delete_node(&replace_node, prev, *(int *)(replace_node->data));
		}
	} else {
                printf("\nNode with this element unavailable\n");
	}

	printf("\nExiting delete node function\n");
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


extern void
delete_tree (struct node *head)
{
	if (head == NULL) {
		return;
	}
	delete_tree(head->left);	
	delete_tree(head->right);	
	if (head->left) {
		printf("\nCleaning up node with data %d\n", *((int *)head->left->data));
		free_node(head->left);
		head->left = NULL;
	}
	if (head->right) {
		printf("\nCleaning up node with data %d\n", *((int *)head->right->data));
		free_node(head->right);
		head->right = NULL;
	}
}


extern void
mirror_tree (struct node *head)
{
	struct node *temp = NULL;

	if (head == NULL)
		return;
	mirror_tree(head->left);
	mirror_tree(head->right);
	temp = head->left;
	head->left = head->right;
	head->right = temp;
}
