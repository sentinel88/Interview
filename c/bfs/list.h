#ifndef _LIST_H
#define _LIST_H

struct node
{
	void		*data;
	struct node	*next;
};

extern int 
insert_node (struct node **head, void *data);

extern int 
insert_node_rear (struct node **head, struct node **tail, void *data);

extern int 
insert_node_pos (struct node **head, int pos, void *data);

extern int 
delete_node (struct node **head, struct node **tail);

extern int 
delete_node_pos (struct node **head, int pos);

extern void
print_list (struct node *head);

#endif
