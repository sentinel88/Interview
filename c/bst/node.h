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

extern int 
delete_node (struct node **head, void *data);

extern void
postorder (struct node *head);

extern void
inorder (struct node *head);

extern void
preorder (struct node *head);

#endif
