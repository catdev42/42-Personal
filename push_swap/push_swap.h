/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:51:44 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/05 04:15:17 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

typedef struct d_list
{
	int				x;
	int				order;
	struct d_list	*prev;
	struct d_list	*next;
}					t_dlist;

char				**ft_split_ps(char const *s, char c);
char				**ft_free_split_ps(char **arr, size_t index);
size_t				ft_wordcount_ps(char const *s, char c);

int					push(t_dlist **stack_from, t_dlist **stack_to);

void				ft_dlstadd_front(t_dlist **head, t_dlist *new);
void				ft_dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist				*ft_dlstlast(t_dlist *lst);
t_dlist				*ft_dlstnew(int content);

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
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
*/
#endif