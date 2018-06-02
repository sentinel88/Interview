#include "heap_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 9999999


void
min_heapify(hNode *ptr, int i, int size)
{
        //printf("\nInside max heapify\n");
        int smallest = i;
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        hNode *temp = NULL;

        if ((left < size) && ptr[i].value > ptr[left].value)
                smallest = left;
        if ((right < size) && ptr[smallest].value > ptr[right].value)
                smallest = right;
        if (smallest != i) {
                temp = &ptr[i];
                ptr[i].value = ptr[smallest].value;
                ptr[i].aptr = ptr[smallest].aptr;
		ptr[i].index = ptr[smallest].index;
                ptr[smallest].value = temp->value;
                ptr[smallest].aptr = temp->aptr;
		ptr[smallest].index = temp->index;
                min_heapify(ptr, smallest, size);
        }
        //printf("\nExiting max heapify\n");
}


void
max_heapify(hNode *ptr, int i, int size)
{
#ifdef _INCLUDE
	//printf("\nInside max heapify\n");
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	hNode *temp = NULL;

	if ((left < size) && ptr[i] < ptr[left])
		largest = left;
	if ((right < size) && ptr[largest] < ptr[right])
		largest = right;
	if (largest != i) {
		temp = &ptr[i];
		ptr[i].value = ptr[largest].value;
		ptr[i].aptr = ptr[largest].aptr;
		ptr[largest].value = temp->value;
		ptr[largest].aptr = temp->aptr;
		max_heapify(ptr, largest, size);
	}
	//printf("\nExiting max heapify\n");
#endif
}


void
build_max_heap(hNode *ptr, int size)
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


void
build_min_heap(hNode *ptr, int size)
{
        //printf("\nInside build max heap\n");
        int i = size >> 1;

        printf("i: %d\n", i);
        while (i >= 0) {
                min_heapify(ptr, i, size);
                i--;
        }
        //printf("\nExiting build max heap\n");
}


int
extractMin (hNode *ptr, int size)
{
	int value = ptr[0].value;

	ptr[0].index++;
	if (ptr[0].index == ptr[0].size)
	{
		ptr[0].value = INT_MAX;
		min_heapify(ptr, 0, size);
		return value;
	}
	(ptr[0].aptr)++;
	ptr[0].value = *(ptr[0].aptr);
	min_heapify(ptr, 0, size);
	
	return value;
}


void
heapsort(hNode *ptr, int size)
{
#ifdef _INCLUDE
	//printf("\nInside heap sort\n");
	int i = size - 1;	
	hNode *temp = NULL;

	/* First build max heap. This takes O(n) time */
	build_max_heap(ptr, size);
	printf("\nMax Heap\n");
        for (i = 0; i < size; i++) {
                printf("%d ", ptr[i].value);
        }
	i = size - 1;	
	/* Sort the max heap by extracting root each time and replace it with the last slot in the array. Then heapify */
	while (i >= 1) {
		temp = &ptr[0];
		ptr[0].value = ptr[i].value;
		ptr[0].aptr = ptr[i].aptr;
		ptr[i].value = temp->value;
		ptr[i].aptr = temp->aptr;
		size--;
		max_heapify(ptr, 0, size);
		i--;
	}
	//printf("\nExiting heap sort\n");
#endif
}
