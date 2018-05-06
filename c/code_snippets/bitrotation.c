#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct
{
	unsigned int x:2;
	unsigned int y:3;
} bitfields;


static bool
isRotate(unsigned int x, unsigned int y)
{
	unsigned long long int num = x | (unsigned long long int)x << 32;

	while (num >= y)
	{
		if ((unsigned)num == y)
			return true;
		num = num >> 1;
	}

	return false;
}

int
main (int argc, char *argv[])
{
	unsigned int x = 123;
	unsigned int y = 2147483678;
	bitfields var;
	
	if (isRotate(x, y))
		printf("\nTrue\n");
	else
		printf("\nFalse\n");
	printf("\nSizeof struct var is %lu\n", sizeof(var));

	return 0;
}
