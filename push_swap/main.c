/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/05 02:00:48 by myakoven         ###   ########.fr       */
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
	// i++;
	// (sizeof(arr));
	return (i);
}

int	main(int argc, char **argv)
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		argv = ft_split_ps(argv[1], ' ');
	stack_a = ft_init_list(argv);
	if (!stack_a)
		return (2);
	// First stack Initialized with values
	if (argc == 2)
		// freeing the malloced argv in case of "283 563 166"
		ft_free_split_ps(argv, (ft_arrsize_twod(argv) - 1));
	return (0);
}

t_dlist	**ft_init_list(const char const **argv)
{
	size_t	i;
	t_dlist	*temp;
	t_dlist	**stack_a_init;

	i = 1;
	*stack_a_init = ft_dlstnew(ft_atoi(argv[i++]));
	while (argv[i])
	{
		temp = ft_dlstnew(ft_atoi(argv[i++]));
		if (!temp)
			ft_dlstclear(stack_a_init);
		ft_dlstadd_back(stack_a_init, temp);
		i++;
	}
	temp = ft_dlstnew(ft_atoi(argv[i++]));
	if (!temp)
		ft_dlstclear(stack_a_init);
	ft_dlstadd_back(stack_a_init, temp);
	return (stack_a_init);
}
