#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 
swap(char *str1, char *str2)
{
	int i = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = len1 < len2 ? len1 : len2;
	char temp;
	while (len)
	{
		temp = str1[i];
		str1[i] = str2[i];
		str2[i] = temp;
		len--;
		i++;
	}
	if (!str1[i])
	{
		strcat(&str1[i], &str2[i]);
		str2[i] = '\0';
	} else {
		strcat(&str2[i], &str1[i]);
		str1[i] = '\0';
	}
}


int
main(int argc, char *argv[])
{
	char str1[10] = "geeks";
	char str2[10] = "forgeeks";
	swap(str1, str2);
	printf("str1: %s, str2: %s\n", str1, str2);
	return 0;
}
