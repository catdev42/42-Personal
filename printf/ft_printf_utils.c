/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:58:34 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/17 19:42:42 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	if (str = NULL)
	{
		ft_putstr_fd("null", 1);
        return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printnum(va_list arg)
{
	int		sign;
	int		count;
	char	*numstr;

	count = 0;
	numstr = ft_itoa(arg);
	count = ft_printstr(numstr);
	free(numstr);
	return (count);
}
