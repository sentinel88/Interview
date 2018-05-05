#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

static char *
stringcpy (char *dst, const char *src)
{
	while (*src)
	{
		*dst = *src;	
		dst++;
		src++;
	}	
	*dst = '\0';
}

int
main (int argc, char *argv[])
{
	char *src = (char *) malloc (sizeof(char) * MAX_SIZE);
	char *dst = (char *) malloc (sizeof(char) * (MAX_SIZE));
	char array[10] = {0};

	//stringcpy(dst, "My name is Nishanth. Hello, How are you?");
	//printf("%s\n", dst);
	printf("Sizeof src: %lu, Sizeof array: %lu\n", sizeof(src), sizeof(array));
	free(src);
	free(dst);

	return 0;
}
