#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
swap (int *a, int *b) 
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


static int
partition (int *ptr, int low, int high)
{
	//printf("\nInside merge\n");
	int i = low;
	int j = high;
	int pivot = low;
	int temp;
	int cur = j;

	while (i < j) {
		if (cur == j) {
			if (ptr[j] >= ptr[i]) {
				j--;
				cur = j;
				continue;
			} else {
				/* swap ptr[i] and ptr[j]. Change cur to i */
				swap(&ptr[i], &ptr[j]);
				cur = i;
			}
		} else {
			if (ptr[i] <= ptr[j]) {
				i++;
				cur = i;
				continue;
			} else {
				/* swap ptr[i] and ptr[j]. Change cur to j */
				swap(&ptr[i], &ptr[j]);
				cur = j;
			}
		}
	}
	return cur;
	//printf("\nExiting merge\n");
}


static void
quicksort(int *ptr, int low, int high)
{
	//printf("\nInside merge sort\n");
	int pos;

	if (low >= high)
		return;
	pos = partition(ptr, low, high);
	quicksort(ptr, low, pos);
	quicksort(ptr, pos + 1, high);
	//printf("\nExiting merge sort\n");
}


int 
main(int argc, char *argv[])
{
	//int array[] = {23, 13, 15, 2, 71, 46, 89, 22, 10, 32};
	int array[] = {12, 11, 13, 5, 6, 7};
	int i = 0;
	int size = (sizeof(array) / sizeof(array[0]));

	/* Perform Merge Sort */
	quicksort(array, 0, size - 1);
	/* Print the sorted array (ascending order) */
	printf("\nSorted Array\n");
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}

