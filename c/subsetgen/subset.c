#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int size = 0;


static void
printArray(int *ptr, int *flags)
{
	int i = 0;
	while (i < size) {
		if (flags[i])
			printf("%d ", ptr[i]);
		i++;
	}
	printf("\n");
}


static void
subsetgen(int *ptr, int *flags, int index)
{
	if (index == size) {
		printArray(ptr, flags);
		return;
	}
	flags[index] = 1;
	subsetgen(ptr, flags, index + 1);
	flags[index] = 0;
	subsetgen(ptr, flags, index + 1);	
}


int 
main(int argc, char *argv[])
{
	//int array[] = {23, 13, 15, 2, 71, 46, 89, 22, 10, 32};
	int array[] = {12, 11, 13, 5, 6, 7};
	int i = 0;
	size = (sizeof(array) / sizeof(array[0]));
	int *flags = (int *) calloc(sizeof(int), size);

	/* Perform Merge Sort */
	subsetgen(array, flags, 0);
	return 0;
}

