#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define WORD_SIZE 100

static char *
get_new_node (void)
{
	char *data = NULL;
	int size = WORD_SIZE;

	data = (char *) malloc (sizeof(char) * WORD_SIZE);
	printf("Enter a word to store in the table");
	fgets(data, size, stdin);
	printf("\nData: %s", data);
	return data;
}


int main (int argc, char *argv[])
{
	char ch;
	int choice;
	int hash_value = 0;
	int ret_val = 0;
	char *data = NULL;
	char str[WORD_SIZE];
	int size = WORD_SIZE;

	hash_table = (struct node **) calloc (sizeof(struct node *), HASH_TABLE_SIZE);
	while (1) {
		printf("\nMENU\n\n");
		printf("1. Insert a word\n");
		printf("2. Search and Delete a word\n");
		printf("3. Display\n");
		printf("\nEnter your choice\n");
		scanf(" %d", &choice);
		switch (choice)
		{
			case 1:
				data = get_new_node();
				hash_value = data[0] - 97;
				ret_val = insert_node(&hash_table[hash_value], (void *)data);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 2:
				printf("\nEnter a word to search for in the table and delete: ");
				fgets(str, size, stdin);
				hash_value = str[0] - 97;
				ret_val = delete_node(&hash_table[hash_value], str);
				if (ret_val)
					printf("\nOperation failed\n");
				break;
			case 3:
				print_list(hash_table);
				break;
			default:
				printf("\nWrong choice. Doing nothing\n");
		}
		printf("Do you want to continue (y/n) ??");
		scanf(" %c", &ch);
		if (ch == 'n' || ch == 'N') {
			printf("\nBreaking the driver loop\n");
			break;
		}
	}
	return 0;
}
