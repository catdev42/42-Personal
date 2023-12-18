/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:02:10 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/18 22:39:13 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkcase(va_list args, const char format);

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!string)
		return (-1);
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (!ft_strchr("cspdiuxX%", string[i + 1]))
				return (-1);
			count += ft_checkcase(args, string[++i]);
		}
		else
			count += ft_printchar(string[i]);
		i++;
	}
	va_end(args);
		return (count);
}

int	ft_checkcase(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (format == '%')
		count += ft_printchar('%');
	else if (format == 'd' || format == 'i')
		count += ft_printnum(va_arg(args, int));
	else if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_printptr(va_arg(args, uintptr_t));
	else if (format == 'u')
		count += ft_printuns(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_printhex(va_arg(args, unsigned long long int), format);
	return (count);
}
