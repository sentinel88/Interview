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
genStrings (char *str, char *temp, int newlen, int index, int len)
{
	if (index == len)
	{
		temp[index] = '\0';
		printf("%s\n", temp);
		return;
	}
	for (int i = 0; i < newlen; i++)
	{
		swap(&str[0], &str[i]);
		temp[index] = str[0];
		genStrings(str, temp, newlen, index + 1, len);
		swap(&str[0], &str[i]);
	}
}


static void
processStr (char *str, int len)
{
	int res_ind = 0;
	int i = 0;
	unsigned char visited[26] = {0};

	for (i = 0; i < len; i++)
	{
		if (!visited[str[i] - 'A'])
		{
			visited[str[i] - 'A'] = 1;	
			str[res_ind] = str[i];
			res_ind++;
		}
	}
	str[res_ind] = '\0';
}


int
main (int argc, char *argv[])
{
	char str[] = "ABA";
	int len = strlen(str);

	processStr(str, len);
	char *temp = (char *) malloc(sizeof(char) * (len + 1));
	int newlen = strlen(str);

	genStrings(str, temp, newlen, 0, len);
	
	return 0;
}
