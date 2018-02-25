#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int fun (int *arr)
{
	printf("\nBefore: %p\n", arr);
	arr++;
	printf("\nAfter: %p\n", arr);
}*/

int 
myatoi(char *str, int n)
{
	if (n == 1)
		return ((10^(n-1) * (*str - '0')));

	int temp = myatoi(str + 1, n - 1);
	return ((10^(n-1) * (*str - '0')) + temp);
}

int 
main (int argc, char *argv[])
{
	char ch = 0x45;
	int arr[] = {1, 2, 3, 4};
        char str[] = "112";
	int n = strlen(str);
	printf("\nNumber = %d\n", myatoi(str, n));	
	return 0;
}
