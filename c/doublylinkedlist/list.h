#ifndef _LIST_H
#define _LIST_H

struct node
{
	void		*data;
	struct node	*next;
	struct node	*prev;
};


extern int 
insert_node (struct node **head, void *data);

extern int 
insert_node_pos (struct node **head, int pos, void *data);

extern int 
delete_node (struct node **head);

extern int 
delete_node_pos (struct node **head, int pos);

extern void
print_list (struct node *head);

extern void
mergesort (struct node **head,);

extern void
convert_to_bst (struct node **head);

#endif
