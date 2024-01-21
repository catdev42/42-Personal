/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:03:38 by jadyar            #+#    #+#             */
/*   Updated: 2024/01/06 18:30:04 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	buffer_data(int fd, char **buff_txt, char *tmp_stor)
{
	char	*mergd_txt;
	int		read_chrs;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		tmp_stor[i++] = '\0';
	read_chrs = read(fd, tmp_stor, BUFFER_SIZE);
	if (read_chrs <= 0)
	{
		if (read_chrs == -1)
		{
			if (*buff_txt)
			{
				free(*buff_txt);
				*buff_txt = NULL;
			}
		}
		return (read_chrs);
	}
	mergd_txt = ft_strjoin_and_free(*buff_txt, tmp_stor);
	if (!mergd_txt)
		return (-1);
	*buff_txt = mergd_txt;
	return (read_chrs);
}

static void	extract_l(char **l, char **buff_txt)
{
	char	*nl_ptr;
	int		line_len;

	nl_ptr = ft_strchr(*buff_txt, '\n');
	if (nl_ptr != NULL)
	{
		line_len = nl_ptr - *buff_txt + 1;
	}
	else
	{
		line_len = ft_strlen(*buff_txt);
	}
	if (*l != NULL)
	{
		free(*l);
	}
	*l = ft_substr(*buff_txt, 0, line_len);
}

static void	res_buff(char **buff_txt)
{
	char	*n_buff;
	char	*nl_ptr;

	nl_ptr = ft_strchr(*buff_txt, '\n');
	if (nl_ptr)
	{
		n_buff = ft_strdup(nl_ptr + 1);
		free(*buff_txt);
		*buff_txt = n_buff;
	}
	else
	{
		free(*buff_txt);
		*buff_txt = NULL;
	}
}

char	*process_line(char **buff_txt, char *line)
{
	if (*buff_txt && **buff_txt)
	{
		extract_l(&line, buff_txt);
		res_buff(buff_txt);
	}
	else
	{
		free(*buff_txt);
		*buff_txt = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff_txt[MAX_FD];
	char		*tmp_stor;
	char		*line;
	int			read_status;

	line = NULL;
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff_txt[fd])
		buff_txt[fd] = ft_strdup("");
	tmp_stor = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_stor)
		return (NULL);
	while (!ft_strchr(buff_txt[fd], '\n'))
	{
		read_status = buffer_data(fd, &buff_txt[fd], tmp_stor);
		if (read_status <= 0)
			break ;
	}
	free(tmp_stor);
	line = process_line(&buff_txt[fd], NULL);
	return (line);
}
