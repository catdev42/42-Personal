/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:14:09 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/18 01:32:45 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_numlen(unsigned int u);
char	*ft_uitoa(unsigned int u);

int	ft_printuns(unsigned int u)
{
	char	*numstr;

	numstr = ft_uitoa(u);
	ft_putstr_fd(numstr, 1);
	free(numstr);
	return (ft_numlen(u));
}

char	*ft_uitoa(unsigned int u)
{
	size_t	len;
	char	*numstr;

	len = ft_numlen(u);
	numstr = malloc(sizeof(char) * (len + 1)) if (!numstr) return (NULL);
	numstr[len] = 0;
	while (len > 0)
	{
		numstr[--len] = u % 10 + '0';
		u /= 10;
	}
	return (numstr);
}

size_t	ft_numlen(unsigned int u)
{
	size_t	i;

	i = 0;
	while (u > 0)
	{
		u = u / 10;
		i++;
	}
	return (i);
}
