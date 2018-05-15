#ifndef _TRIE_H
#define _TRIE_H

/* Implementing a dictionary using trie data structure */

#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 52

typedef struct node
{
	//char ch;
	bool isleaf;
	struct node *next[ALPHABET_SIZE];	
} trieNode;


Node *
getNode (void);

int
removeNode (trieNode *);

int 
addWord (trieNode **, const char *);

int
removeWord (trieNode **, const char *);

int 
searchWord (trieNode *, const char *);


static void
_display (trieNode *, char *, int);

void
display (trieNode *);

#endif
