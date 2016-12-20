#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	printf("\nString is %s\n", str);	
	reverse(str, 0, strlen(str));
	printf("\nReversed string is %s\n", str);	

	return 0;
}
