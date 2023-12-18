/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:35:39 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/18 22:08:42 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_it_hex(unsigned int num, char format)
{
	while (num > 15)
	{
		ft_print_it_hex(num / 16, format);
		num = num % 16;
	}
	if (num <= 9)
		ft_putchar_fd((num + '0'), 1);
	if (num > 9)
	{
		if (format == 'x')
			ft_putchar_fd((num + 'a' - 10), 1);
		else
			ft_putchar_fd((num + 'A' - 10), 1);
	}
}

int	ft_printhex(unsigned int num, char format)
{
	int	count;

	count = 0;
	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_print_it_hex(num, format);
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}
