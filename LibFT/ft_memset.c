/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:17:22 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/18 20:32:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char *arr;

	i = 0;
	arr = (unsigned char *)s;
	while (i < n)
	{
		arr[i++] = (unsigned char)c;
	}
	return (s);
}