/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:11:55 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/29 01:52:04 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>


char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoinbuff(char const *s1, char const *buff);
char	*ft_takeline(char *line, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_clearfree(char *buffer, char *line);
// int	ft_read(int fd, char *line, char *newline, char *buffer, int bytes_read);


#endif
