#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
fun (int x)
{
	static int num = 0;
	num = x; 
	printf("\nNum: %d\n", num);
	return 0;
}


int
main (int argc, char *argv[])
{
	fun(5);
	return 0;
}
