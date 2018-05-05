#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*static int
myatoi(char *str, int len)
{
	int i = 0;
	int res = 0;

	while (i < len)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	
	return res;
} */

static int
myatoi(char *str, int n)
{
	if (n == 1)
		return (*str - '0');
	return ( (10 * myatoi(str, n - 1)) + str[n - 1] - '0');
}

int
main (int argc, char *argv[])
{
	char str[] = "112";
	int num;

	num  = myatoi(str, strlen(str));
	printf("Number: %d\n", num);

	return 0;
}
