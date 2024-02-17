/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:45:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/17 04:32:49 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int		pfd[argc - 4][2];
	int		pid;
	t_info	basics;
	char	cmdpath[101];
	int		i;

	ft_init_basics(argc, argv, env, &basics);
	if (argc != 5)
		return (pip_error(1));
	i = 0;
	while (i < argc - 4)
		if (pipe(pfd[i++]) == -1)
			return (3);
	dup2(basics.fd_in, 0);
	i = 0;
	while (i + 2 < argc - 2)
	{
		pid = fork();
		if (pid == -1)
			return (4);
		if (pid == 0)
			child(&basics, i, pfd, cmdpath);
		i++;
	}
	close(pfd[i][1]);
	dup2(pfd[i][0], 0);
	dup2(basics.fd_out, 1);
	execute(argv[argc - 2], env, cmdpath);
}

void	child(t_info *basics, int round, int pfd[][2], char *cmdpath)
{
	int	i;

	// int	fd_read;
	// int	fd_write;
	// dup2(pfd[round - 1][0], 0);
	if (round == 0)
		// dup2(pfd[round][0], 0);
		dup2(pfd[round][1], 1);
	else
	{
		close(pfd[round - 1][1]);
		dup2(pfd[round - 1][0], 0);
		dup2(pfd[round][1], 1);
	}
	// if (round != 0)
	// 	dup2(fd_read, 0);
	// dup2(fd_write, 1);
	i = 1;
	while (i < (basics->argc) - 4)
	{
		if (pfd[round][0] != pfd[i][0])
			close(pfd[i][0]);
		if (pfd[round][1] != pfd[i][1])
			close(pfd[i][1]);
		i++;
	}
	execute((basics->argv)[round + 2], basics->env, cmdpath);
}

void	ft_init_basics(int argc, char **argv, char **env, t_info *basics)
{
	basics->fd_in = open(argv[1], O_RDONLY);
	basics->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (basics->fd_in < 0 || basics->fd_out < 0)
		pip_error(2);
	basics->argc = argc;
	basics->argv = argv;
	basics->env = env;
}

int	pip_error(int err)
{
	if (err == 1)
	{
		ft_printf("Correct implementation: ./a.out infile 'cmd1' 'cmd2' outfile");
		return (1);
	}
	if (err == 2)
	{
		ft_printf("Infile Open Error");
		return (2);
	}
	if (err == 3)
	{
		ft_printf("Path is over 100 characters long");
		return (3);
	}
	return (0);
}
// int		fdfiles[2];

// int		fdfiles[2];

// fdfiles[0] = open(argv[1], O_RDONLY);
// fdfiles[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// if (fdfiles[0] < 0 || fdfiles[1] < 0)
// 	return (pip_error(2));

/*
	pid1 = fork();
	if (pid1 == -1)
		return (4);
	if (pid1 == 0)
		child_process(argv, p_fd, env, fd_in, cmdpath);
	dup2(fd_out, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	close(p_fd[0]);
	execute(argv[3], env, cmdpath);
*/

//

// while (i < (basics->argc) - 3)
// {
// 	if (pfd[i][0] != fd_read)
// 		close(pfd[i][0]);
// 	if (pfd[i][1] != fd_write)
// 		close(pfd[i][1]);
// }
