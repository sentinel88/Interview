#ifndef _HEAP_LIB_H
#define _HEAP_LIB_H


typedef struct
{
	int *aptr; // Pointer to the element in the array which this node is catering to
	int value; // Actual integer value
	int size; // Size of the array
	int index; // Position in the array
} hNode;


void
max_heapify(hNode *, int, int);


void
min_heapify(hNode *, int, int);


void
build_min_heap(hNode *, int);


void
build_max_heap(hNode *, int);


void
heapsort(hNode *, int);

int
extractMin(hNode *, int);

#endif
