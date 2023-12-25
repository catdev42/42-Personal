/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:38:49 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/22 00:43:05 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}

void	del_char(char *str)
{
	free(str);
}