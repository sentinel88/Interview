#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
	unsigned short int num = 32896;
	int NO_OF_BITS = sizeof(num) * 8;
	unsigned short int revnum = 0;
	int i = 0;

	printf("Num: %d, size: %u\n", num, NO_OF_BITS);
	while (i < NO_OF_BITS)
	{
		if (num & (1 << i))
			revnum |= 1 << (NO_OF_BITS - 1 - i);
		i++;
	}
	printf("\nReverse of the bits is: %u\n", revnum);

	return 0;
}
