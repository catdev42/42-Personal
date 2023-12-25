/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:11:55 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/25 20:36:21 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);

/******* LIST STUFF *******/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				del_char(char *str);
#endif
