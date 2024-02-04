#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("read_error.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
