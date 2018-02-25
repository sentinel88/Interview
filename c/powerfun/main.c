#include <stdio.h>
#include <stdlib.h>

int
fac (int num, int exp)
{
	if (num == 0)
		return 0;
	if (exp == 0)
		return 1;
	int temp = fac(num, exp/2);
	if (exp % 2 == 0)
		return (temp * temp);
	return (num * temp * temp);
}


int 
main (int argc, char *argv[])
{
	int num = 2;
	int exp = 6;
	printf("\n%d^%d = %d\n", num, exp, fac(num, exp));
	return 0;
}
