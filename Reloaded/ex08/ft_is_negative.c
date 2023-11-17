/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:13:23 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/10 09:26:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else 
		write(1, "P", 1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("-3");
	ft_is_negative(-3);
}
*/
