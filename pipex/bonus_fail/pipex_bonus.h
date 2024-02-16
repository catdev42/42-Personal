/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:43:55 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/16 23:21:47 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

int		pip_error(int err);
void	execute(char *cmd, char **env);
char	*ft_findpath(char *cmd, char **env);
char	*ft_jointhree(char const *s1, char const *s2, char const *s3);
char	*ft_findpathenv(char *name, char **env);
// void	child_process(char **argv, int *p_fd, char **env, int fd_in);

void	pip_open_files(int argc, char **argv, int *fdinout);
void	child_last_process(char *argv, int *p_fd, char **env, int fd_out);
void	ch_mid(char *argv, int *pfd_read, char **env, int **pfd, int argc);
void	child_first_process(char *argv, int *p_fd, char **env, int fd_in);
#endif