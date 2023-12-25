/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:16:30 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/25 20:41:31 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t read(int fildes, void *buf, size_t nbyte);

char	*get_next_line(int fd)
{
	static t_list	**storage;
	char			*buf;

	storage = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buf, BUFFER_SIZE);
}
