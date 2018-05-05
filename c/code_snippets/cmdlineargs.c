#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char *argv[])
{
	char **argvec = NULL;
	int i = 0;
	int len = 0;
	
	argvec = (char **) malloc (sizeof(char *) * argc);
	for (i = 0; i < argc; i++)
	{
		argvec[i] = (char *) malloc (strlen(argv[i]) * sizeof(char));
		strcpy(argvec[i], argv[i]);
	}

	for (i = 0; i < argc; i++)
	{
		printf("%s\t%s\n", argv[i], argvec[i]);
		free(argvec[i]);
	}
	free(argvec);

	return 0;
}
