#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int size = 0;
static int level = 0;
static int *output = NULL;


static void
printArray(int *out)
{
	int i = 0;
	
	for (i = 0; i < size; i++) {
		printf("%d ", out[i]);
	}
}


static void
permute(int *ptr, int *flags, int curr_index)
{
	int i = 0;

	level++;
	output[level - 1] = ptr[curr_index];
	if (level == size) {
		printArray(output);
		printf("\n");
		level--;
		return;
	}
	while (i < size) {
		if (flags[i]) {
			i++;
			continue;
		}
		flags[i] = 1;
		permute(ptr, flags, i);
		flags[i] = 0;
		i++;
	}
	level--;
}


int 
main(int argc, char *argv[])
{
	//int array[] = {23, 13, 15, 2, 71, 46, 89, 22, 10, 32};
	int array[] = {12, 11, 13, 5, 6, 7};
	//int array[] = {1, 2, 3};
	int i = 0;
	size = (sizeof(array) / sizeof(array[0]));
	int *flags = (int *) calloc(sizeof(int), size);
	output = (int *) calloc(sizeof(int), size);

	/* Perform Merge Sort */
	//subsetgen(array, flags, 0);
	for (i = 0; i < size; i++) {
		//curr_index = i;
		flags[i] = 1;
		permute(array, flags, i);
		flags[i] = 0;
	}
	return 0;
}

