#ifndef _LIST_H
#define _LIST_H

#define HASH_TABLE_SIZE 26

struct node
{
	void		*data;
	struct node	*next;
};

extern struct node **hash_table;

extern int 
insert_node (struct node **head, void *data);

extern int 
delete_node (struct node **head, char *data);

extern void
print_list (struct node **head);

#endif
