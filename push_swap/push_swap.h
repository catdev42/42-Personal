/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:51:44 by myakoven          #+#    #+#             */
/*   Updated: 2024/01/31 02:38:16 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

#ifndef PUSH_SWAP
# define PUSH_SWAP

typedef struct d_list
{
	int				x;
	int				order;
	struct d_list	*prev;
	struct d_list	*next;
}					t_dlist;

/*
t_list				*ft_lstnew(void *content);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **first, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
*/
#endif