/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:23:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/05 15:29:00 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	int	a;
	int	b;

	a = fork();
	b = fork();
	printf("HELLO FROM ALL\n");
	if (a)
		if (!b)
			printf("we are in the child process of the main process a && !b\n");
	if (a)
		if (b)
			printf("we are in the main branch of the main process! a \
					&& b\n");
	if (!a)
		if (b)
			printf("we are in the main process of child process\n");
	if (!a)
		if (!b)
			printf("child of child !a && !b\n");
	wait(NULL);
}
