/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:16:30 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/26 21:32:14 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t read(int fildes, void *buf, size_t nbyte);

char	*get_next_line(int fd)
{
	t_list	**storage;
	char	*buf;
	char	*line;
	int		n_index;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// bytes_read = read(fd, buf, BUFFER_SIZE);
	// if (bytes_read == -1)
	// {
	// 	free(buf);
	// 	return (NULL);
	// }
	// if (bytes_read == 0)
	// {
	// 	free(buf);
	// 	return (ft_calloc(1, 1));
	// }
	if (storage == NULL)
		storage = ft_lstnew(buf);
	// n_index = ft_strchr(buf, '/n');
	// if (n_index && storage)
	line = ft_calloc(sizeof(char) * (ft_makelist(fd, storage, buf) + 1));
	ft_makestring(storage, line);
	ft_lstclear(storage, del_char(char *str));
	return (line)
}

int	ft_makelist(int fd, t_list **storage, char *buf)
{
	t_list	*item;
	char	*buf;
	int		item_counter;
	int		n_index;
	int		bytes_read;

	buf = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	// must know which number list item we are on and index of the '/n' character
	char_counter = 0;
	item_counter = 0;
	item = storage;
	if (!ft_strchr(buf, '/n'))
		while (!ft_strchr(item->content, '/n'))
		{
			item->next = ft_lstnew(buf);
		}
	return (item_counter * BUFFER_SIZE + char_counter);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (str);
	return (NULL);
}
