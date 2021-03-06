#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
merge (int *ptr, int low, int mid, int high)
{
	//printf("\nInside merge\n");
	int i = low;
	int j = mid + 1;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int larr[n1], rarr[n2];
	int k = 0;

	printf("low = %d mid = %d high = %d n1 = %d, n2 = %d\n", low, mid, high, n1, n2);
	while (i <= mid) {
		larr[k++] = ptr[i++];
		printf("%d ", larr[k - 1]);
	}
	printf("\n");
	k = 0;
	while (j <= high) {
		rarr[k++] = ptr[j++];
		printf("%d ", rarr[k - 1]);
	}
	printf("\n");
	i = 0;
	j = 0;
	k = low;
	
	while ( (i < n1) && (j < n2)) {
		if (larr[i] <= rarr[j]) {
			ptr[k++] = larr[i++];
		} else {
			ptr[k++] = rarr[j++];
		}
		printf("%d ", ptr[k - 1]);
	}
	while (i < n1)
		ptr[k++] = larr[i++];
	while (j < n2)
		ptr[k++] = rarr[j++];
	printf("\nMerged Array\n");
	for (i = low; i <= high; i++) {
		printf("%d ", ptr[i]);
	}
	printf("\n\n");
	//printf("\nExiting merge\n");
}


static void
mergesort(int *ptr, int low, int high)
{
	//printf("\nInside merge sort\n");
	int mid;

	if (low >= high)
		return;
	mid = (low + high) / 2;
	mergesort(ptr, low, mid);
	mergesort(ptr, mid + 1, high);
	merge(ptr, low, mid, high);
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
	mergesort(array, 0, size - 1);
	/* Print the sorted array (ascending order) */
	printf("\nSorted Array\n");
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}

