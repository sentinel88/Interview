#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void
dec2bin (int num)
{
	if (num == 0)
	{
		//printf("\n");
		return;
	}
	dec2bin(num/2);
	printf("%d", num%2);
}


int
main (int argc, char *argv[])
{
	int num;

	printf("Enter a number\n");
	scanf("%d", &num);
	if (num)
	{
		dec2bin(num);
		printf("\n");
	} else {
		printf("%d\n", (int) 0);
	}

	return 0;
}
