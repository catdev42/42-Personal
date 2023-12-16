/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:02:10 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/16 23:16:30 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *string, ...)
{
    va_list args; 
	size_t	count;
	
	count = 0;
    va_start = (args, string);`
	while (string[i] != '%')
	{
		ft_putchar_fd(string[i], 1);
		i++;
		count++;
	}
	if (string[i++] == '%')
        count++;
	if (string[i] == '%')
	    count += ft_printchar('%', 1);
	else if (string[i] && ft_strchr('cspdiuxX%', string[i]))
		ft_checkcase(string[i]);
}

void ft_checkcase(char c)
{
    
}

#include <stdio.h>
int	main(void)
{
	ft_printf("Hello there, just testing %%");
    printf("Hello there, just testing %%");
}
