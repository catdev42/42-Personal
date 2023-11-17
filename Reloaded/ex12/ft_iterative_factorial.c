/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:15:32 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/10 11:27:51 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if ((nb == 0) || (nb > 12))
		return (0);
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%i", ft_iterative_factorial(6));
}
*/
