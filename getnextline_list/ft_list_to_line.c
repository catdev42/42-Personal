/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:41:56 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/27 02:37:07 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_list_to_line(t_list **list)
{
	char	*line;
	t_list	*node;
	int		i;
	int		j;
	size_t	size;

	if (!list)
		return (NULL);
	node = list;
	size = ft_getsize(node);
	line = calloc((size + 1), 1);
	if (!line)
		return (NULL);
	j = 0;
	while (node->content[j] != '/n')
		j++;
	j++;
	i = 0;
	while (node && i < size)
	{
		while (node->content[j] && i < size)
		{
			line[i++] = node->content[j++];
			if (node->content[j] == '/n')
			{
				line[i] = 0;
				return (line);
			}
		}
		node = node->next;
		j = 0;
	}
	return (line);
}

int	ft_getsize(t_list *node)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (node->content[i] != '/n')
		i++;
	i++;
	while (node && node->content[i] != '/n')
	{
		while (node->content[i] && node->content[i] != '/n')
		{
			size++;
			i++;
		}
		lst = lst->next;
		i = 0;
	}
	return (size);
}
