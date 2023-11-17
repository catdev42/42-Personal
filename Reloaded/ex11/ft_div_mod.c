/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:08:16 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/10 11:10:49 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>
int main(void)
{
	int a;
	int b;
	ft_div_mod(4,3,&a, &b);
	printf("4/3 & 4%%3: %i, %i", a,b);
}
*/
