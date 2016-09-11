#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
max_heapify(int *ptr, int i, int size)
{
	//printf("\nInside max heapify\n");
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	int temp = 0;

	if ((left < size) && ptr[i] < ptr[left])
		largest = left;
	if ((right < size) && ptr[largest] < ptr[right])
		largest = right;
	if (largest != i) {
		temp = ptr[i];
		ptr[i] = ptr[largest];
		ptr[largest] = temp;
		max_heapify(ptr, largest, size);
	}
	//printf("\nExiting max heapify\n");
}


static void
build_max_heap(int *ptr, int size)
{
	//printf("\nInside build max heap\n");
	int i = size >> 1;
	
	printf("i: %d\n", i);
	while (i >= 0) {
		max_heapify(ptr, i, size);
		i--;
	}
	//printf("\nExiting build max heap\n");
}


static void
heapsort(int *ptr, int size)
{
	//printf("\nInside heap sort\n");
	int i = size - 1;	
	int temp = 0;

	/* First build max heap. This takes O(n) time */
	build_max_heap(ptr, size);
	printf("\nMax Heap\n");
        for (i = 0; i < size; i++) {
                printf("%d ", ptr[i]);
        }
	i = size - 1;	
	/* Sort the max heap by extracting root each time and replace it with the last slot in the array. Then heapify */
	while (i >= 1) {
		temp = ptr[0];
		ptr[0] = ptr[i];
		ptr[i] = temp;
		size--;
		max_heapify(ptr, 0, size);
		i--;
	}
	//printf("\nExiting heap sort\n");
}


int 
main(int argc, char *argv[])
{
	int array[] = {23, 13, 15, 2, 71, 46, 89, 22, 10, 32};
	int i = 0;
	int size = (sizeof(array) / sizeof(array[0]));

	/* Perform heap sort */
	heapsort(array, size);
	/* Print the sorted array (ascending order) */
	printf("\nSorted Array\n");
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}

