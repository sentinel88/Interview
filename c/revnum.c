#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int 
_revnum (int num, int *result)
{
	if (num == 0)
		return 0;
	*result = (*result * 10) + (num % 10);
	_revnum(num / 10, result);
	return *result;
}

int 
revnum (int num)
{
	int result = 0;
	return (_revnum(num, &result));
}


int 
main (int argc, char *argv[])
{
	int num = 5926;

	printf("\nThe reverse of %d is %d\n", num, revnum(num));

	return 0;
}
