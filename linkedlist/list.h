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
delete_node (struct node **head);

extern void
print_list (struct node *head);

#endif
