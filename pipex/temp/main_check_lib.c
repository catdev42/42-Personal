#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include "./libft/libft.h"
// #include "./get_next_line/get_next_line.h"

int	main(void)
{
	ft_printf("%i", ft_strlen("hello"));
	ft_printf("HELLO PRINTF");
	int	fd;

	fd = open("read_error.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
