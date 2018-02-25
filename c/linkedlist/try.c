#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun (int (*ptr)[3])
{
	printf("\nValue: %d\n", ptr[1][1]);
	return 0;
}

int
main (int argc, char *argv[])
{
	int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int **ptr = (int **)arr;

	printf("\nSize of the 2d array is %lu\n", sizeof(arr));	
	printf("Address of 2d array is %p\tsize: %lu\n", ptr, sizeof(ptr));
	fun(arr);

	return 0;
}
