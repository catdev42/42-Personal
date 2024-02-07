

#include "push_swap.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->x = content;
	new->order = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *node)
{
	t_dlist	*ptr;

	if (!node || !lst)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	ptr = ft_dlstlast(*lst);
	ptr->next = node;
	node->prev = ptr;
}

void	ft_dlstadd_front(t_dlist **head, t_dlist *node)
{
	if (head && node)
	{
		node->next = *head;
		node->next->prev = node;
		*head = node;
	}
}

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist *tmp;
	t_dlist *prev;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	*lst = NULL;
}