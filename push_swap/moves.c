/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:46:38 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/05 03:05:36 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* IS IT BETTER TO RETURN THE NEW STACK POINTER???*/

int	push(t_dlist **stack_from, t_dlist **stack_to)
{
	t_dlist	*temp_move;
	t_dlist	*temp_newhead;

	if (!stack_from)
	{
		ft_printf("The from stack is empty, nothing more to push");
		return (0);
	}
	// SHOULD NOTIFY PROGRAM THAT LIST IS EMPTY
	temp_move = *stack_from;
	temp_newhead = temp_move->next;
	if (stack_from && stack_to)
	{
		temp_move->next = stack_to;
		if (stack_to)
			(*stack_to)->prev = temp_move;
		*stack_to = temp_move;
	}
	// if (current == *stack_a)
	// {
	// 	*stack_a = current->next;
	// 	current->next = *stack_b;
	// 	current->prev = NULL;
	// 	*stack_b = current;
	// }
	// else if (current == *stack_b)
	// {
	// 	*stack_b = current->next;
	// 	current->next = *stack_a;
	// 	current->prev = NULL;
	// 	*stack_a = current;
	// }
	return (1);
}

int	swap(t_dlist const **stack)
{
	t_dlist	*first;
	t_dlist	*second;
	t_dlist	*temp;

	if (stack)
	{
		ft_printf("nothing to swap (error)");
		return (0);
	}
	first = stack;
	second = (*stack)->next;
	// temp = first;
	first->next = first->next->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
	return (1);
}
