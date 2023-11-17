/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:30:30 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/10 15:38:34 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("hello help difference result: %i",ft_strcmp("hello", "help"));
	printf("hello hello difference result: %i",ft_strcmp("hello", "hello"));
}
*/
