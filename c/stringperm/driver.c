#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void 
swap (char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}


void 
_genStrings(char *str, char *temp, int len, int index)
{
	if (index == len)
	{
		temp[index] = '\0';
		printf("%s\n", temp);
		return;	
	}
	for (int i = index; i < strlen(str); i++)
	{
		char temp1 = str[i];
		swap(&str[i], &str[index]);
		temp[index] = str[index];
		_genStrings(str, temp, len, index + 1);
		swap(&str[i], &str[index]);
	}
}

void 
genStrings (char *str, int len)
{
	char *temp = (char *) malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
	{
		printf("\nMemory allocation failed\n");
		return;
	}
	_genStrings(str, temp, len, 0);
	free(temp);
}

int
main (int argc, char *argv[])
{
	char str[] = "Nishanth";
	int len = 5;
	
	for (int i = 1; i <= len; i++)
	{
		printf("\nPossible strings of length %d\n", i);
		genStrings(str, i);
	}
	
	return 0;
}
