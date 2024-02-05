/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/04 21:21:46 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

int	ft_arrsize_twod(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	i++;
	// (sizeof(arr));
	return (i);
}

int	main(int argc, char **argv)
{
	// t_dlist	**stack_a;
	// t_dlist	**stack_b;
	if (argc < 2)
		return (1);
	if (argc == 2)
		argv = ft_split_ps(argv[1], ' ');
	// ft_init_list(argv);
	ft_printf("%s\n", argv[1]);
	ft_printf("%i", ft_arrsize_twod(argv));
	ft_free_split_ps(argv, (ft_arrsize_twod(argv) - 1));
	// ft_free_split_ps(argv, 0);
	return (0);
}
