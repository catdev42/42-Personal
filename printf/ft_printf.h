/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:10:52 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/18 22:10:32 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

int	ft_printf(const char *string, ...);

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printnum(int n);

int	ft_printuns(unsigned int u);

int	ft_printptr(uintptr_t address);
int	ft_printhex(unsigned int num, char format);

#endif
