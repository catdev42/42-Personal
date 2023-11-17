/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:11:06 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/10 12:35:32 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = nb / 2;
	if (i > 46340)
		i = 46340;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i * i > nb)
		i = i / 2;
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%i", ft_sqrt(2147483647));
}
*/
