/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:32:05 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/10 09:37:18 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
#include <stdio.h>
int main(void)
{
	int a = 3;
	int b = 7;
	ft_swap(&a, &b);
	printf("Originally 3, 7 - now %i,%i", a, b); 
}
*/
