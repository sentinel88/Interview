#ifndef _TRIE_H
#define _TRIE_H

/* Implementing a dictionary using trie data structure */

#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct node
{
	char ch;
	bool isleaf;
	struct node *next[ALPHABET_SIZE];	
} Node;


Node *
getNode (char ch);

int 
addWord (char *word);

int
removeWord (char *word);

int 
searchWord (char *word);

#endif
