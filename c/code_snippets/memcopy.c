#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
memcopy (void *dest, const void *src, size_t len)
{
	char *dst = (char *) dest;
	char *sr = (char *) src;
	int i = 0;

	if ( (dest > src) &&
		(dest <= (src + len - 1)) )
	{
		i = len - 1;
		dst[len] = '\0';
		while (i >= 0)
        	{
                	dst[i] = sr[i];
                	i--;
        	}	
	} else {
		i = 0;
		while (i < len)
		{
			dst[i] = sr[i];
			i++;
		}
		dst[i] = '\0';
	}	
}


int
main (int argc, char *argv[])
{
	char *dest = (char *) malloc (sizeof(char) * 30);
//	char *src = (char *) malloc (sizeof(char) * 100);
	char *str = "My name is Nishanth";

	strcpy(dest, str);
	memcopy(dest + 1, dest, strlen(str));
	printf("%s\n", dest + 1);

	return 0;
}
