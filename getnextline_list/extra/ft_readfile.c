/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:58:53 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/27 03:25:45 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns the LINE

char	*ft_readfile(int fd, char *buffer)
{
	int		bytes_read;
	char	*line;
	char	*oldline;
	int		i;

	// read old buffer
	if (!buffer)
		return (NULL);
	if (ft_strlen(buffer) > 0)
		line = ft_strdup(buffer);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		oldline = line;
	}
	return (list);
}
// line should contain only the line with new line at the end.
// buffer should contain only the content after new line at the end