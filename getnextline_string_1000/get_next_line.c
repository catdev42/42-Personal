/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 03:02:39 by myakoven          #+#    #+#             */
/*   Updated: 2024/01/04 20:34:33 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_clearfree(buffer, line));
	line = ft_strjoinbuff(line, buffer);
	if (!line)
		return (ft_clearfree(buffer, line));
	line = ft_read(fd, line, buffer);
	if (!line)
		return (NULL);
	line = ft_takeline(line, buffer);
	if (!ft_strlen(line))
		return (ft_clearfree(buffer, line));
	return (line);
}

/* take substr and clean up buffer to be without prev line*/
char	*ft_takeline(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*newline;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	newline = ft_substr(line, 0, i);
	free(line);
	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (buffer[j] == '\n')
		j++;
	buffer = ft_memmove(buffer, (buffer + j), (BUFFER_SIZE - j));
	j = (BUFFER_SIZE - j);
	while (j < BUFFER_SIZE)
		buffer[j++] = 0;
	return (newline);
}

char	*ft_read(int fd, char *line, char *buffer)
{
	int		i;
	int		bytes_read;
	char	*newline;

	if (ft_strchr(buffer, '\n'))
		return (line);
	while (buffer)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < BUFFER_SIZE && bytes_read >= 0)
		{
			i = bytes_read;
			while (i < BUFFER_SIZE)
				buffer[i++] = 0;
		}
		newline = ft_strjoinbuff(line, buffer);
		if (!newline || bytes_read == -1)
			return (ft_clearfree(buffer, line));
		if (line != newline)
			free(line);
		line = newline;
		if (ft_strchr(line, '\n') || bytes_read == 0)
			break ;
	}
	return (line);
}

char	*ft_strjoinbuff(char *s1, char const *buff)
{
	int		len_s1;
	int		i;
	int		j;
	char	*string;

	len_s1 = ft_strlen(s1);
	i = -1;
	j = 0;
	if (BUFFER_SIZE >= 50)
		string = malloc((len_s1 + BUFFER_SIZE) + 1);
	else if (BUFFER_SIZE < 50 && (len_s1 == 0 || len_s1 % 1000 == 0))
		string = malloc(len_s1 + 1001);
	else if (BUFFER_SIZE < 50 && len_s1 % 1000 < (998 - BUFFER_SIZE))
		string = s1;
	else
		string = malloc(len_s1 + 1000 + (998 - len_s1 % 1000) + 1);
	if (!(string))
		return (NULL);
	while (++i < (len_s1) && string != s1)
		string[i] = s1[i];
	if (string == s1)
		i = len_s1;
	while (i < (len_s1 + BUFFER_SIZE + 1))
		string[i++] = buff[j++];
	return (string);
}

char	*ft_clearfree(char *buffer, char *line)
{
	ft_bzero(buffer, BUFFER_SIZE);
	if (!line)
		return (NULL);
	free(line);
	return (NULL);
}
/*
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
*/
/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
*/
