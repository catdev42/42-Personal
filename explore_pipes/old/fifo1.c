#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*arr;

	
	arr = "black, ginger, while, tuxedo, etc...";
    if (mkfifo("fifofile", 0777) == -1)
		// if (errno != EEXIST)
			printf("Could not create fifo file\n");
	fd = open("fifofile", O_WRONLY);
	if (fd == -1)
		return (1);
	if (write(fd, arr, strlen(arr)) == -1)
		return (2);
	close(fd);
}
