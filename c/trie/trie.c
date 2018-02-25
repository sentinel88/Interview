#include <stdio.h>
#include <stdlib.h>
#include <trie.h>

Node *
getNode (char ch)
{
        Node *ptr = (Node *) malloc (sizeof(Node));
        if (ptr == NULL)
	{
		printf("\nUnable to allocate memory for the Node\n");
		return NULL;
	}
        ptr->isleaf = false;
        ptr->ch = ch;
        memset(ptr->next, 0, sizeof(Node *) * ALPHABET_SIZE);
        return ptr;
}


int
addWord (char *word)
{
	
}
