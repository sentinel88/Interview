#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void 
reverse (char*, int, int);

void 
reverseStmt (char *str)
{
	int len = strlen(str);
	int start = -1;
	int i;
	reverse(str, 0, len);
	printf("\nReversed string is %s\n", str);
	for (i = 0; i < len; i++)
	{
		if ( (start != -1) && (str[i] == ' ') )
		{
			printf("i: %d, start: %d\n", i, start);
			reverse(&str[start], 0, i - start);
			printf("\n%s \n", str);
			while (str[i] == ' ')
				i++;
			start = i;
			continue;
		}
		if (start == -1 && str[i] != ' ')
			start = i;
	}
}


void 
reverse (char *str, int index, int len)
{
	if (index == len)
		return;
	reverse(str, index + 1, len);
	if (index < (len/2))
		return;
	char temp;
	temp = str[index];
	str[index] = str[len - index - 1];
	str[len - index - 1] = temp;
}


int 
main (int argc, char *argv[])
{
	char str[] = "Amaze";
	char sentence[] = "I love programming";

	printf("\nString is %s\n", str);
	printf("Sentence is %s\n", sentence);	
	reverse(str, 0, strlen(str));
	reverseStmt(sentence);
	printf("\nReversed string is %s\n", str);	
	printf("\nReversed sentence is %s\n", sentence);	

	return 0;
}
