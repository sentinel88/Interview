#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

void function1(void)
{
char *s1 = "my";
char * s2 = "program";
char *s3 = strcat(s1,s2);
printf("%s",s3);
}

void function2(void)
{
char *s1 = (char *) malloc(SIZE * sizeof(char));
strcpy(s1,"my");
char *s2 = "program";
char *s3 = strcat(s1,s2);
printf("%s\n",s3);
}

int
main (int argc, char *argv[])
{	
	return 0;
}
