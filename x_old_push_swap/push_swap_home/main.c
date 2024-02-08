/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/07 23:31:27 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

// int	ft_arrsize_twod(char **arr)
// {
// 	int	i;

// 	if (!arr)
// 		return (0);
// 	i = 0;
// 	while (arr[i])
// 		i++;
// 	// i++;
// 	// (sizeof(arr));
// 	return (i);
// }

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
	// Possible the check array should be checked earlier
	if (!ft_checkarray(argc, argv) && argc > 2)
		return (0);
	else if (!ft_checkarray(argc, argv) && argc == 2)
		return (ft_free_split_ps(argv, (ft_arrsize_twod(argv) - 1)));
	// Initialize stack_a
	stack_a = ft_init_list(argc, argv);
	if (!stack_a)
		return (2);
	// Stack_a initialized with values
	ft_orders_list(stack_a);
	// ft_index_list(stack_a, stack_b);
	if (argc == 2)
		// freeing the malloced argv in case of "283 563 166"
		ft_free_split_ps(argv, (ft_arrsize_twod(argv) - 1));
	return (0);
}

int	ft_checkarray(int argc, char **arr)
{
	size_t	i;
	size_t	j;

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

int	ft_matrixlen(const char **s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
// i = 0;
// 	while (arr[i])
// 	{
// 		j = 0;
// 		while (arr[j])
// 		{
// 			if (i != j && arr[i] == arr[j])
// 			{
// 				write(2, "Error\n", 6);
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}

/******THIS NEEDS A COUNT LIMITER!!!*******/
t_dlist	**ft_init_list(int argc, const char const **argv)
{
	size_t	i;
	t_dlist	*temp;
	t_dlist	*last;
	t_dlist	**stack_a_init;

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
			ft_dlstclear(stack_a_init);
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

/*t_dlist	**ft_init_list(const char const **argv)
{
	size_t	i;
	t_dlist	*temp;
	// t_dlist *last;
	t_dlist	**stack_a_init;

	i = 1;
	*stack_a_init = ft_dlstnew(ft_atoi(argv[i++]));
	while (argv[i])
	{
		prev =
		temp = ft_dlstnew(ft_atoi(argv[i++]));
		if (!temp)
			ft_dlstclear(stack_a_init);
		// ***!!!*** MAYBE JUST ADD NEW NODE TO PREV NODE INSTEAD OF ALWAYS ITERATING
		ft_dlstadd_back(stack_a_init, temp);
		// i++;
	}
	temp = ft_dlstnew(ft_atoi(argv[i++]));
	if (!temp)
		ft_dlstclear(stack_a_init);
	ft_dlstadd_back(stack_a_init, temp);
	return (stack_a_init);
}*/