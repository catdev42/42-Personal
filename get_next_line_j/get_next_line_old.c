/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:05:03 by jadyar            #+#    #+#             */
/*   Updated: 2024/01/21 22:49:04 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff_txt;
	char		*tmp_stor;
	char		*line;
	int			read_status;

	buff_txt = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff_txt)
		buff_txt = ft_strdup("");
	tmp_stor = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_stor)
		return (NULL);
	while (!ft_strchr(buff_txt, '\n'))
	{
		read_status = buffer_data(fd, &buff_txt, tmp_stor);
		if (read_status <= 0)
			break ;
	}
	free(tmp_stor);
	return (process_line(&buff_txt, line));
}

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


char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*n_str;
	size_t	i;
	size_t	j;

	n_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!n_str)
	{
		free(s1);
		return (NULL);
	}

	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		n_str[j++] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		n_str[j++] = s2[i];
	n_str[j] = '\0';
	free(s1);
	return (n_str);
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




