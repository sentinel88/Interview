#ifndef _LIST_H
#define _LIST_H

struct node
{
	void		*data;
	struct node	*left;
	struct node	*right;
};

extern int 
insert (struct node **head, void *data);

extern void 
delete_node (struct node **head, struct node *parent, int key);

extern void
postorder (struct node *head);

extern void
inorder (struct node *head);

extern void
preorder (struct node *head);

extern void
delete_tree (struct node *head);

extern void 
mirror_tree (struct node *head);

extern void
free_node (struct node *ptr);

#endif
