#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"

#define MAX_WORD_SIZE 100

#define char2ascii(char ch) \
	(ch > 96)? (ch - 96) : (26 + (ch - 65))

#define ascii2char(int val) \
	(val < 27)? (96 + val) : (val - 26 + 65)


static int
isLeafNode (trieNode *root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->next[i])
			return -1;
	}
	
	return 0;
}


int
removeNode (trieNode *ptr)
{
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		if (ptr->next[i])
		{
			free(ptr->next[i]);
			ptr->next[i] = NULL;
		}
			
	}
	free(ptr);
}


Node *
getNode (void)
{
        trieNode *ptr = (trieNode *) malloc (sizeof(trieNode));
        if (ptr == NULL)
	{
		printf("\nUnable to allocate memory for the Node\n");
		return NULL;
	}
        ptr->isleaf = false;
        memset(ptr->next, 0, sizeof(Node *) * ALPHABET_SIZE);
        return ptr;
}


int
addWord (trieNode **root, const char *word)
{
	int i = 0;
	trieNode *temp = NULL;

	if (*root == NULL)
	{
		*root = getNode();
	}
	*temp = *root;
	while (word[i] != '\0')
	{
		int index = char2ascii(word[i]);
		if (!temp->next[index])
		{
			temp->next[index] = getNode();		
		}
		temp = temp->next[index];
		i++;
	}				
	temp->isleaf = true;
	
	return 0;
}


int
removeWord (trieNode **root, char *word)
{
	if (*word == '\0')
	{
		(*root)->isleaf = false;
		if ( isLeafNode(*root) )
			return 1;
		else 
			return 0;
	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		int index = char2ascii(*word);
		if ((*root)->next[index])
		{
			if (removeWord((*root)->next[index], word + 1))
			{
				removeNode((*root)->next[index]);
				return 1;
			}
			break;
		}
	}
	return 0;
}


int 
searchWord (trieNode *root, char *word)
{
	if (root == NULL)
	{
		printf("\nEmpty trie\n");
		return -1;
	}
	while (*word)
	{
		int index = char2ascii(*word);
		if (!root->next[index])
			break;
		root = root->next[index];
		word++;
	}
	if (!*word && (root->isleaf == true))
		return 0;

	return -1;
}


void
_display (trieNode *root, char *word, int index)
{
	if (root == NULL)
		return;
	if (root->isleaf == true)
	{
		word[index] = '\0';
		printf("%s\n", word);
	}
		
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (!root->next[i])
			continue;
		//printf("%c", ascii2char(i));
		word[index] = ascii2char(i);
		display(root->next[i], word, index + 1);
	}
}


void
display (trieNode *root)
{
	char word[MAX_WORD_SIZE];
	
	memset(word, 0, MAX_WORD_SIZE);
	_display(root, word, 0);
}
