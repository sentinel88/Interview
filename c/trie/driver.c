#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int
main (int argc, char *argv[])
{
	trieNode *root = NULL;
	int ch;

	while (1)
	{
		printf("\nMENU\n");
		printf("1.   Add a word\n");
		printf("2.   Delete a word\n");
		printf("3.   Search for a word\n");
		printf("4.   Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				addWord(&root, word);
				break;
			case 2:
				removeWord(&root, word);
				break;
			case 3:
				searchWord(&root, word);
				break;
			case 4: 
				exit(0);
			default:
				printf("\nWrong choice\n");
				break;
		}
	}
		
	return 0;
}
