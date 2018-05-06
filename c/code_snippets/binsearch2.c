#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int
binsearchmod (int *arr, int low, int high, int num)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (arr[mid] == num)
	{
		return mid;
	} 
	if (arr[low] <= arr[mid])
	{
		if (num >= arr[low] && num < arr[mid])
			return binsearchmod (arr, low, mid - 1, num);
		return binsearchmod (arr, mid + 1, high, num);
	} 
	if (num > arr[mid] && num <= arr[high])
	{
		return binsearchmod (arr, mid + 1, high, num);
	} 
	return binsearchmod (arr, low, mid - 1, num);

	return -1;
}

int
main (int argc, char *argv[])
{
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int size = sizeof(arr)/sizeof(int);
	int num;

	printf("\nEnter the number to be searched in the array\n");
	scanf("%d", &num);
	printf("\nBinary search result: %d\n", binsearchmod(arr, 0, size - 1, num));

	return 0;
}
