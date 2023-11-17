/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:53:48 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/15 18:12:10 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	
	if (min >= max)
		return (0);
	range = malloc(sizeof(int) * (max - min));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>
int main(void)
{
	int *arr = ft_range(3,11);
	printf("Print range of 3 and 11: %i, %i, %i, %i", arr[0], arr[1], arr[2], arr[8]);
}
*/
