// #include <errno.h>
// #include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	execlp("ping", "ping", "-c", "3", "google.com", NULL);
	printf("Success!");
	return (0);
}
