#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int fun1()
{
	char *s;

	s=(char *) malloc (MAX*sizeof(char));
	s="hello";
	free(s);
	return 0;
}

int
main (int argc, char *argv[])
{
	fun1();
	
	return 0;
}
