/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/04 18:18:05 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;

	if (argc < 2)
		return (1);
	if (argc == 2)
		ft_split_ps(argv, ' ');
	// ft_init_list(argv);
	ft_printf("%s", argv[1]);
	return (0);
}
