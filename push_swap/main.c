/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/06 19:57:28 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		argv = ft_split_ps(argv[1], ' ');
	// Possible the check array should be checked earlier
	if (!ft_checkarray(argc, argv) && argc > 2)
		return (0);
	else if (!ft_checkarray(argc, argv) && argc == 2)
		return ((long int)ft_free_split_ps(argv, (ft_matrixlen(argv) - 1)));
	// Initialize stack_a
	stack_a = ft_init_list(argc, argv);
	if (!stack_a)
		return (2);
	ft_printf("%i", (*stack_a)->next->x);
	// TO DO
	// ft_index_list(stack_a);
	if (argc == 2)
		// freeing the malloced argv in case of "283 563 166"
		ft_free_split_ps(argv, (ft_matrixlen(argv) - 1));
	return (0);
}

int	ft_checkarray(int argc, char **arr)
{
	int	i;
	int	j;

	if (argc == 2)
		argc = ft_matrixlen(arr);
	i = 1;
	while (arr[i] && i < argc)
	{
		if (ft_atol(arr[i]) > INT_MAX || ft_atol(arr[i]) < INT_MIN)
			return (error_fail());
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j++]))
				return (error_fail());
		}
		j = 0;
		while (arr[j])
		{
			if (i != j && !ft_strncmp(arr[i], arr[j], ft_strlen(arr[i]) + 1))
				return (error_fail());
			j++;
		}
		i++;
	}
	return (1);
}

int	error_fail(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	ft_matrixlen(char **arr)
{
	int	i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/******THIS NEEDS A COUNT LIMITER!!!*******/
t_node	**ft_init_list(int argc, char **argv)
{
	int		i;
	t_node	*temp;
	t_node	*last;
	t_node	**stack_a_init;

	stack_a_init = NULL;
	if (argc == 2)
		argc = ft_matrixlen(argv);
	i = 1;
	*stack_a_init = ft_dlstnew(ft_atoi(argv[i++]));
	temp = *stack_a_init;
	while (argv[i] && i < argc)
	{
		last = temp;
		temp = ft_dlstnew(ft_atoi(argv[i++]));
		if (!temp)
			return (ft_dlstclear(stack_a_init));
		last->next = temp;
		temp->prev = last;
	}
	// WHY IS THIS HERE?
	// temp = ft_dlstnew(ft_atoi(argv[i++]));
	// if (!temp)
	// 	ft_dlstclear(stack_a_init);
	// ft_dlstadd_back(stack_a_init, temp);
	return (stack_a_init);
}

// int	ft_arrsize(char **arr)
// {
// 	int	i;

// 	if (!arr)
// 		return (0);
// 	i = 0;
// 	while (arr[i])
// 		i++;
// 	return (i);
// }
