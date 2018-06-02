#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap_lib.h"

int
main (int argc, char *argv[])
{
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {6, 7, 8, 9, 10};
	int arr3[] = {11, 12, 13, 14, 15};
	int arr4[] = {16, 17, 18, 19, 20};
	int arr5[] = {21, 22, 23, 24, 25};
	int size = sizeof(arr1)/sizeof(arr1[0]);
	int narr = 5;
	int *ptr_arr[5] = {&arr1[0], &arr2[0], &arr3[0], &arr4[0], &arr5[0]};
	int finSize = narr * size;
	int array[finSize];
	hNode minHeap[narr];
	int minValue;
	int k = 0;
	int i;

	for (i = 0; i < narr; i++)
	{
		minHeap[i].value = *ptr_arr[i];
		minHeap[i].aptr = ptr_arr[i];
		minHeap[i].size = size;
		minHeap[i].index = 0;
	}
	build_min_heap(minHeap, narr);
	do
	{
		minValue = extractMin(minHeap, narr);
		array[k++] = minValue;
	} while(k < finSize);
	printf("\nThe final sorted array is\n");
	for (i = 0; i < finSize; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	return 0;
}
