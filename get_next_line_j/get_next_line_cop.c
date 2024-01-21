/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_cop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:05:03 by jadyar            #+#    #+#             */
/*   Updated: 2024/01/21 19:45:07 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
STEP 1
char	*get_next_line(int fd);
int		read_buffer_data(int fd, char **buff_txt, char *longbuff);
char	*ft_strjoin(char *buff_txt, char *longbuff);

STEP 2
char	*process_line(char **buff_txt, char *line);
void	extract_l(char **l, char **buff_txt);
void	res_buff(char **buff_txt);
*/

char	*get_next_line(int fd)
{
	static char	*buff_txt;
	char		*longbuff;
	char		*line;

	// int			read_status;
	// buff_txt will word as the read buffer
	// longbuff will work as the thing we allocating all the read stuff into from buff_txt
	if (!buff_txt)
	{
		buff_txt = malloc(BUFFER_SIZE + 1);
		if (!buff_txt)
			return (NULL);
		ft_bzero(buff_txt, (BUFFER_SIZE + 1));
	}
	longbuff = NULL;
	if (buff_txt)
		longbuff = ft_strjoin(buff_txt, longbuff);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		// gotta free everything that was initialized,
		// like freeing and deleting variables that stores any addresses
		return (ft_clean(&buff_txt, longbuff));
	// buff_txt = ft_strdup("");
	// if (!longbuff)
	// 	return (NULL);
	/*READ THINGS, should now return longbuff*/
	// MODIFY read should read up to new line OR to read = o
	// while (!ft_strchr(longbuff, '\n'))
	// {
	longbuff = read_buffer_data(fd, buff_txt, longbuff);
	if (!longbuff)
		return (ft_clean(&buff_txt, longbuff));
	// }
	// free(longbuff);
	line = process_line(longbuff, &buff_txt);
	if (!line)
		return (ft_clean(&buff_txt, longbuff));
	free(longbuff);
	return (line);
}

char	*read_buffer_data(int fd, char *buff_txt, char *longbuff)
{
	char	*mergd_txt;
	int		read_chrs;

	// int		i;
	read_chrs = 1;
	while (read_chrs > 0 && !ft_strchr(longbuff, '\n'))
	{
		ft_bzero(buff_txt, BUFFER_SIZE);
		// i = 0;
		// while (i < BUFFER_SIZE + 1)
		// 	buff_txt[i++] = '\0';
		read_chrs = read(fd, buff_txt, BUFFER_SIZE);
		if (read_chrs <= 0)
			// the freeing will now happen inside get_next_line function
			return (NULL);
		// {
		// 	if (read_chrs == -1)
		// 	{
		// 		if (*buff_txt)
		// 		{
		// 			free(*buff_txt);
		// 			*buff_txt = NULL;
		// 		}
		// 	}
		// 	return (read_chrs);
		// }
		mergd_txt = ft_strjoin(buff_txt, longbuff);
		if (!mergd_txt)
			return (NULL);
		free(longbuff);
		longbuff = mergd_txt;
	}
	return (longbuff);
}

char	*ft_strjoin(char *buff_txt, char *longbuff)
{
	char	*n_str;
	size_t	i;
	size_t	j;

	n_str = malloc(sizeof(char) * (ft_strlen(longbuff) + BUFFER_SIZE + 1));
	if (!n_str)
		// if null gets returned all the way back to get_next_line function,
		// if will clear everything...
		return (NULL);
	// size_t cannot be negative so i made everything 0+
	i = 0;
	j = 0;
	while (longbuff && longbuff[i] != '\0')
		n_str[j++] = longbuff[i++];
	i = 0;
	while (buff_txt && buff_txt[i] != '\0')
		n_str[j++] = buff_txt[i++];
	n_str[j] = '\0';
	// if you free buff_txt,
	// you have to also set it to NULL... we are not reallocating buff_txt anymore.
	// switched the roles of tmp buffer and buff_txt
	// free(buff_txt);
	// free(longbuff); -- this is getting freed in the calling function
	return (n_str);
}

// returns line, reallocated buffer by reference (only instance)
// combine everything into process line function
char	*process_line(char *longbuff, char **buff_txt)
{
	char	*tmp_ptr;
	int		line_len;
	char	*line;
	size_t	i;

	// char	*n_buff;
	// if (*buff_txt && **buff_txt)
	// {
	// 	extract_l(&line, buff_txt);
	// 	res_buff(buff_txt);
	// }
	// else
	// {
	// 	free(*buff_txt);
	// 	*buff_txt = NULL;
	// }
	i = 0;
	line = NULL;
	if (longbuff)
	{
		tmp_ptr = ft_strchr(longbuff, '\n');
		if (tmp_ptr)
			line_len = tmp_ptr - longbuff + 1;
		else
			line_len = ft_strlen(longbuff);
		line = ft_substr(longbuff, 0, line_len);
		// char	*ft_substr(char const *s, unsigned int start, size_t len);

	}

	
	tmp_ptr = ft_strchr(*buff_txt, '\n');
	if (tmp_ptr)
	{
		while (tmp_ptr[++i])
			*buff_txt[i] = tmp_ptr[i];
		while (i < BUFFER_SIZE)
			*buff_txt[i++] = 0;
	}
	// {
	// 	tmp_ptr = ft_strdup(tmp_ptr + 1);
	// 	free(*buff_txt);
	// 	*buff_txt = tmp_ptr;
	// }
	else
	{
		free(*buff_txt);
		*buff_txt = NULL;
	}
	return (line);
}

// void	extract_l(char **l, char **buff_txt)
// {
// 	char	*tmp_ptr;
// 	int		line_len;

// 	tmp_ptr = ft_strchr(*buff_txt, '\n');
// 	if (tmp_ptr != NULL)
// 		line_len = tmp_ptr - *buff_txt + 1;
// 	else
// 		line_len = ft_strlen(*buff_txt);
// 	if (*l != NULL)
// 		free(*l);
// 	*l = ft_substr(*buff_txt, 0, line_len);
// }

// void	res_buff(char **buff_txt)
// {
// 	char	*tmp_ptr;
// 	char	*n_buff;

// 	tmp_ptr = ft_strchr(*buff_txt, '\n');
// 	if (tmp_ptr)
// 	{
// 		n_buff = ft_strdup(tmp_ptr + 1);
// 		free(*buff_txt);
// 		*buff_txt = n_buff;
// 	}
// 	else
// 	{
// 		free(*buff_txt);
// 		*buff_txt = NULL;
// 	}
// }


