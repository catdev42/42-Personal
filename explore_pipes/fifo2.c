#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	// char	*arr;
	char	readarr[100];
    // if (mkfife("fifofile", 0777) == -1)
    //     if (errno != EEXIST)
    //         printf("Could not create fifo file\n");

	// arr = "black, ginger, while, tuxedo, etc...";
	fd = open("fifofile", O_RDONLY);
	if (fd == -1)
		return (1);
	if (read(fd, readarr, 99) == -1)
		return (2);
	printf("%s", readarr);
	close(fd);
	return (0);
}
