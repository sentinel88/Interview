#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
	int i = 1024;
	int j = 19;
	int start = 2;
	int end = 6;

	j = j << start;
	int rmask = (1 << (end + 1)) - 1;
	int lmask = ~((1 << start) - 1);
	
	i = (i & (~(rmask & lmask))) | j;
	printf("Final value: %d\n", i);

	return 0;
}
