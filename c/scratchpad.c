#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
main (int argc, char *argv[])
{
	char str[] = "Nishanth";
	char ch;
	int len = strlen(str);
	int i = 0;
	
	while (i < (len/2))
	{
		ch = str[i];
		str[i] = str[len - i - 1];
		str[len - i -1] = ch;
		i++;
	}
	printf("\n%s\n", str);

	int num = 6;
	int no_of_bits = sizeof(int) * 8;
	int revnum = 0;
	i = 0;

	printf("\nNum: %d\n", num);

	while (num)
	{
		if (num & 1)
		{
			revnum |= (1 << (no_of_bits - i - 1));
		}
		num = num >> 1;
		i++;
	}
	printf("\nReverse of number: %d\n", revnum);
	
	return 0;
}
