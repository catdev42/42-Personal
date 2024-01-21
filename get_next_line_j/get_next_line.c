/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:05:03 by jadyar            #+#    #+#             */
/*   Updated: 2024/01/21 22:03:39 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ORDER:

STEP 1
char	*get_next_line(int fd);
int		read_buffer_data(int fd, char **buff_txt, char *longbuff);
char	*ft_strjoin(char *buff_txt, char *longbuff);

STEP 2 (COMBINED NOW)
char	*process_line(char **buff_txt, char *line);
void	extract_l(char **l, char **buff_txt);
void	res_buff(char **buff_txt);

*/

char	*get_next_line(int fd)
{
	static char	*buff_txt;
	char		*longbuff;

	longbuff = NULL;
	if (!buff_txt)
	{
		buff_txt = malloc(BUFFER_SIZE + 1);
		if (!buff_txt)
			return (NULL);
		ft_bzero(buff_txt, (BUFFER_SIZE + 1));
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_clean(&buff_txt, longbuff));
	longbuff = ft_strjoin(buff_txt, longbuff);
	if (!longbuff)
		return (ft_clean(&buff_txt, longbuff));
	longbuff = read_buffer_data(fd, buff_txt, longbuff);
	if (!longbuff)
		return (ft_clean(&buff_txt, longbuff));
	longbuff = process_line(longbuff, buff_txt);
	if (!longbuff)
		return (ft_clean(&buff_txt, longbuff));
	// if (buff_txt && !ft_strlen(buff_txt))
	// {
	// 	free(buff_txt);
	// 	buff_txt = NULL;
	// }
	if (longbuff && !ft_strlen(longbuff))
		return (ft_clean(&buff_txt, longbuff));
	return (longbuff);
}

char	*read_buffer_data(int fd, char *buff_txt, char *longbuff)
{
	char	*merged_text;
	int		read_chrs;

	read_chrs = 1;
	while (read_chrs > 0 && !ft_strchr(longbuff, '\n'))
	{
		ft_bzero(buff_txt, BUFFER_SIZE);
		read_chrs = read(fd, buff_txt, BUFFER_SIZE);
		if (read_chrs < 0)
			return (NULL);
		if (read_chrs == 0)
			return (longbuff);
		merged_text = ft_strjoin(buff_txt, longbuff);
		free(longbuff);
		if (!merged_text)
			return (NULL);
		longbuff = merged_text;
	}
	return (longbuff);
}

char	*ft_strjoin(char *buff_txt, char *longbuff)
{
	char	*n_str;
	size_t	i;
	size_t	j;
	size_t	lenlong;

	lenlong = 0;
	if (longbuff)
		lenlong = ft_strlen(longbuff);
	n_str = malloc(sizeof(char) * (lenlong + BUFFER_SIZE + 1));
	if (!n_str)
		return (NULL);
	i = 0;
	j = 0;
	if (longbuff)
	{
		while (i < lenlong)
			n_str[j++] = longbuff[i++];
		i = 0;
	}
	if (buff_txt)
	{
		while (i < ft_strlen(buff_txt))
			n_str[j++] = buff_txt[i++];
	}
	n_str[j] = 0;
	return (n_str);
}

char	*process_line(char *longbuff, char *buff_txt)
{
	char	*newline;
	char	*tmp_ptr;
	size_t	i;
	size_t	j;
	int		line_len;

	// char	*tmp_ptr;
	// int		line_len;
	newline = NULL;
	line_len = 0;
	tmp_ptr = ft_strchr(longbuff, '\n');
	if (tmp_ptr != NULL)
		line_len = tmp_ptr - longbuff + 1;
	else
		line_len = ft_strlen(longbuff);
	newline = ft_substr(longbuff, 0, line_len);
	free(longbuff);
	//was my version:
	// i = 0;
	// while (longbuff[i] != '\n' && longbuff[i])
	// 	i++;
	// if (longbuff[i] == '\n')
	// 	i++;
	// newline = ft_substr(longbuff, 0, i);
	// free(longbuff);
	i = 0;
	j = 0;
	while (buff_txt[j] != '\n' && buff_txt[j])
		j++;
	if (buff_txt[j] == '\n')
		j++;
	while (j < BUFFER_SIZE + 1)
		buff_txt[i++] = buff_txt[j++];
	while (i < BUFFER_SIZE + 1)
		buff_txt[i++] = 0;
	if (!newline)
		return (NULL);
	return (newline);
	/*
	RESET BUFFER CORRECTLY
	tmp_ptr = ft_strchr(buff_txt, '\n');
	if (tmp_ptr && (tmp_ptr + 1) != 0)
	{
		// LEAK
		// tmp_ptr = ft_strdup(tmp_ptr + 1);
		// if (!tmp_ptr)
		// 	return (NULL);
		// free(*buff_txt);
		// *buff_txt = tmp_ptr;
	}
	else
	{
		// free(*buff_txt);
		// *buff_txt = NULL;
	}
	*/
}

char	*ft_clean(char **buff, char *longbuff)
{
	if (buff)
		free(*buff);
	*buff = NULL;
	if (longbuff)
		free(longbuff);
	return (NULL);
}