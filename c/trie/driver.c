#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int
main (int argc, char *argv[])
{
	trieNode *root = NULL;
	int ch;
	char word[MAX_WORD_SIZE];

	while (1)
	{
		printf("\nMENU\n");
		printf("1.   Add a word\n");
		printf("2.   Delete a word\n");
		printf("3.   Search for a word\n");
		printf("4.   Display\n");
		printf("5.   Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the word to be added into the dictionary\n");
				scanf("%s", word);
				addWord(&root, word);
				break;
			case 2:
				printf("\nEnter the word to be deleted from the dictionary\n");
				scanf("%s", word);
				removeWord(&root, word);
				break;
			case 3:
				printf("\nEnter the word to search for in the dictionary\n");
				scanf("%s", word);
				searchWord(root, word);
				break;
			case 4:
				display(root);
				break;
			case 5: 
				exit(0);
			default:
				printf("\nWrong choice\n");
				break;
		}
		if (ch >= 5)
			break;
	}
		
	return 0;
}
