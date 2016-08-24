#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ptr[] = "Hello How are you";

	ptr[3] = 'A';
	printf("%s\n", ptr);
	return 0;
}
