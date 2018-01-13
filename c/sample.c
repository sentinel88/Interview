#include <stdio.h>
#include <stdlib.h>

extern int j;

int
main (int argc, char *argv[])
{
	int k = 10;
	int l = 20;
	j = 10;
//	func();
	printf("%d\n", j);
	return 0;
}
