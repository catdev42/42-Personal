/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:57:06 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/27 02:48:47 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	**ft_readfile(int fd, char *buffer)
{
	t_list	**list;
	t_list	*node;
	int		bytes_read;

	if (!buffer)
		return (NULL);
	list = 0;
	node = 0;
	bytes_read = 1;
	if (!list)
		{
			list = ft_lstnew(buffer);
			if (!list)
				return (ft_freedel(buffer, list));
			node = list;
		}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_freedel(buffer, list));
		
		node->next = ft_lstnew(buffer);
		if (!node->next)
			return (ft_freedel(buffer, list));
		node = node->next;
	}
	return (list);
}

t_list	*ft_freedel(void *temp_content, t_list **new_list, void (*del)(void *))
{
	del(temp_content);
	if (!new_list)
		return (NULL);
	ft_lstclear(new_list, del);
	return (NULL);
}
