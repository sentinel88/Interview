#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
max (int a, int b)
{
	return (a > b ? a : b);
}

static int
min (int a, int b)
{
	return (a < b ? a : b);
}


static int
amtOfWater (int *arr, int size)
{
	int left[size];
	int right[size];
	int result = 0;
	int i;
	
	left[0] = arr[0];
	for (i = 1; i < size; i++)
		left[i] = max(left[i - 1], arr[i]);
	
	right[size - 1] = arr[size - 1];
	for (i = size - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	for (i = 0; i < size; i++)
	{
		result += min(left[i], right[i]) - arr[i];
	}

	return result;
}


int
main (int argc, char *argv[])
{
	//int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	//int arr[] = {3, 0, 0, 2, 0, 4};
	//int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("\nAmount of rain water trapped in the vessel is: %d\n", amtOfWater(arr, size));
	
	return 0;
}
