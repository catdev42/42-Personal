/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:09:28 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/15 01:54:22 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char **arr, int len)
{
	int	i;

	i = 0;
	if (len < 0 || !len)
		len = INT_MAX;
	while (arr[i] && i < len)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
