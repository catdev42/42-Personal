/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:35:39 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/18 01:40:35 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_it(unsigned int num, char format)
{
	while (num > 16)
	{
		ft_print_it(num / 16);
		num = num % 16;
	}
	if (num <= 9)
		ft_putchar_fd((num + '0'), 1);
	if (num > 9)
	{
		if (format == x)
			ft_putchar_fd((num + 'a' - 10), 1);
		else
			ft_putchar_fd((num + 'A' - 10), 1);
	}
}

int	ft_printhex(unsigned int num, char format)
{
	int count;

	count = 0;
	if (num == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	ft_print_it(num, format);
	while (num > 0)
	{
		num = num / 16;
		count++;
	}
	return (count + 2);
}