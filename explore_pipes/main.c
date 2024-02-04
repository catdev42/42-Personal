/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:23:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/04 16:31:13 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

int main(void)
{
    int a = fork();
    int b = fork();
    printf("HELLO FROM ALL\n");
    if (a)
        if (!b)
            printf(" a && !b\n");
    if (a)
        if (b)
            printf(" a && b\n");
            
    if (!a)
        if(b)
            printf(" !a && b\n");

    if (!a)
        if (!b)
            printf("child of child !a && !b\n");

    wait(NULL);

    
}
