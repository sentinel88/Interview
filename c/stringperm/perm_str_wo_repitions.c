#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
swap (char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}


static void
genStrings (char *str, char *temp, int len, int index)
{
	if (index == len)
	{
		temp[index] = '\0';
		printf("%s\n", temp);
		return;
	}
	for (int i = 0; i < len; i++)
	{
		swap(&str[0], &str[i]);
		temp[index] = str[0];
		genStrings(str, temp, len, index + 1);
		swap(&str[0], &str[i]);
	}
}


int
main (int argc, char *argv[])
{
	char str[] = "ABC";
	int len = strlen(str);
	char *temp = (char *) malloc(sizeof(char) * (len + 1));

	genStrings(str, temp, strlen(str), 0);
	
	return 0;
}
