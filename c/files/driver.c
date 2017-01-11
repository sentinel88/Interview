#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int 
main (int argc, char *argv[])
{
	int fd = -1;
	char buf[100];
	int retval = -1;
	off_t val = -1;

	fd = open("try.txt", O_RDWR);	
	if (fd == -1) {
		printf("\nUnsuccessful: file open\n");
		exit(-1);
	}
	retval = read(fd, (void *) buf, 100);
	if (retval <= 0) {
		printf("\nEnd of file\n");
		exit(0);
	}
	buf[retval] = '\0';
	printf("\nBuffer: %s", buf);
	val = lseek(fd, 0, SEEK_SET);
	if (val == (off_t) -1) {
		printf("\nError in setting the position inside the file\n");
		exit(-1);
	}
	retval = write(fd, "Hello", 5);
	if (retval <= 0) {
		printf("\nWrite unsuccessful\n");
		exit(0);
	}
	close(fd);

	return 0;
}
