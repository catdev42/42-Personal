/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:33:51 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/15 17:48:21 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int	i;
	char	*copy = malloc(ft_strlen(src) + 1);
	int	length;

	length = ft_strlen(src);
	if (copy == NULL)
		return (1);
	while (i < length + 1)
	{
		copy[i] = src[i];
		i++;
	}	
	return (copy);
}
