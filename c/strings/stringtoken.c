#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


static bool
isPresentInStr (char ch, char *str)
{
	while (*str)
	{
		if (ch == *str)
			return true;
		str++;
	}
	return false;
}


static char *
strTokenizer (char *str, char *delimiter, char **savestr)
{
	if (str == NULL)
		return NULL;
	int i = 0;
	str = *savestr;
	while (!isPresentInStr(str[i], delimiter))
		i++;
	if (*str == '\0')
		return NULL;
	(*savestr) += (i + 1);
	// Return the token from str to str+i-1
}

int
main (int argc, char *argv[])
{
	char str[] = "My name,is:Nishanth";
	char delimiter[] = " ,:";
	char *savestr = str;
	char *token;
	
	while (token = strTokenizer(str, delimiter, &savestr))
		printf("%s\n", token);

	return 0;		
}
