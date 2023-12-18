/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:02:10 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/18 01:42:37 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start = (arg, string);
	while (string[i])
	{
		while (string[i] != '%')
		{
			ft_putchar_fd(string[i], 1);
			i++;
			count++;
		}
		if (string[i++] == '%')
			count++;
		if (string[i] && string[i++] == '%')
			count += ft_printchar('%', 1);
		else if (string[i] && ft_strchr('cspdiuxX', string[i]))
			count += ft_checkcase(string[i++], arg);
	}
	va_end(arg);
	return (count);
}

void	ft_checkcase(const char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count+=ft_printchar(arg);
	else if (c == 'd' || c = 'i')
		count += ft_printnum(arg);
	else if (c == 's')
		count += ft_printstr(arg);
	else if (c == 'p')
		count += ft_printptr(arg);
	else if (c == 'u')
		count += ft_printuns(arg);
	else if (c == 'x' || c == 'X')
		count += ft_printhex(arg, c);
	
		
}

#include <stdio.h>

int	main(void)
{
	ft_printf("Hello there, just testing %%");
	printf("Hello there, just testing %%");
}
