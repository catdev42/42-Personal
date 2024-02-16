/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:34:20 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/16 16:58:25 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// typedef struct s_commands
// {
// 	char **paths;
	
// } t_commands;

int	main(int argc, char **argv, char **env)
{
	int	pfd[argc - 4][2];
	int	pid;
	int	fdinout[2];
	int	i;
	int	first_cmd_index;

	// int	pid[argc - 3];
	if (argc < 5 || (ft_strncmp("here_doc", argv[1], 9) == 0 && argc < 6))
		return (pip_error(1));
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		first_cmd_index = 3;
	pip_open_files(argc, argv, fdinout);
	i = 0;
	while (i < argc - 4)
		if (pipe(pfd[i++]) == -1)
			return (3);
	i = first_cmd_index - 1;
	while (++i < argc - 1)
	{
		pid = fork();
		if (pid == -1)
			return (4);
		if (i == first_cmd_index && pid == 0)
			child_first_process(argv[i], pfd[i - 2], env, fdinout[0]);
		else if (i == argc - 2 && pid == 0)
			child_last_process(argv[i], pfd[i - 2], env, fdinout[1]);
		else if (pid == 0)
			ch_mid(argv[i], pfd[i - 2], env, pfd, (argc - 3 - 1));
	}
	// last child?
	// dup2(fd_out, 1);
	// dup2(p_fd[0], 0);
	// close(p_fd[1]);
	// close(p_fd[0]);
	// execute(argv[3], env);
}

void	pip_open_files(int argc, char **argv, int *fdinout)
{
	fdinout[0] = open(argv[1], O_RDONLY);
	fdinout[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fdinout[0] < 0 || fdinout[1])
		(pip_error(2));
	exit(1);
}

// argv is usually index 2
void	child_first_process(char **argv, int **p_fd, char **env, int fd_in)
{
	dup2(fd_in, 0);
	dup2(p_fd[0][1], 1);
	close(p_fd[0][0]);
	close(p_fd[0][1]);
	execute(argv[2], env);
}
// argv is usually index 3 to index argc-3
void	ch_mid(char **argv, int *pfd_read, char **env, int **pfd, int argc)
{
	int	i;
	int	*pfd_write;
	int numpfd;

	numpfd = argc - 3;

	i = 0;
	while (pfd_read != pfd[i])
		i++;
	pfd_write = pfd[++i];
	dup2(pfd_read[0], 0);
	dup2(pfd_write[1], 1);
	i = 0;
	close(pfd[0]);
	close(pfd[1]);
	execute(argv[2], env);
}

/*
void	child_middle_process(char **argv, int *p_fd, char **env)
{
	dup2(p_fd[0], 0);
	dup2(fd_out, 1);
	close(p_fd[1]);
	close(p_fd[0]);
	execute(argv[3], env);
}
*/
void	child_last_process(char **argv, int *p_fd, char **env, int fd_out)
{
	dup2(p_fd[0], 0);
	dup2(fd_out, 1);
	close(p_fd[1]);
	close(p_fd[0]);
	execute(argv[3], env);
}
void	execute(char *cmd, char **env)
{
	char	*path;
	char	**command;

	path = ft_findpath(cmd, env);
	if (!path)
		exit(1);
	command = ft_split(cmd, ' ');
	if (execve(path, command, env) == -1)
	{
		ft_putstr_fd("pipex: command path not found for ", 2);
		ft_putendl_fd(command[0], 2);
		ft_freetab(command, 0);
		exit(2);
	}
}

char	*ft_findpath(char *cmd, char **env)
{
	int		i;
	char	*paths;
	char	**splitpaths;
	char	*path;
	char	**splitcommand;

	paths = ft_findpathenv("PATH", env);
	if (!paths)
		return (cmd);
	splitpaths = ft_split(paths, ':');
	splitcommand = ft_split(cmd, ' ');
	i = 0;
	while (splitpaths[i])
	{
		path = ft_jointhree(splitpaths[i], "/", splitcommand[0]);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_freetab(splitpaths, 0);
			ft_freetab(splitcommand, 0);
			return (path);
		}
		free(path);
		i++;
	}
	ft_freetab(splitpaths, 0);
	ft_freetab(splitcommand, 0);
	return (cmd);
}
char	*ft_findpathenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*tempsubstr;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		tempsubstr = ft_substr(env[i], 0, j);
		if (ft_strncmp(name, tempsubstr, 4) == 0)
		{
			free(tempsubstr);
			return (env[i] + j + 1);
		}
		i++;
	}
	free(tempsubstr);
	return (NULL);
}

char	*ft_jointhree(char const *s1, char const *s2, char const *s3)
{
	size_t	len_two;
	size_t	len_all;
	size_t	i;
	size_t	j;
	char	*string;

	i = 0;
	j = 0;
	len_two = ft_strlen(s1) + ft_strlen(s2);
	len_all = len_two + ft_strlen(s3);
	string = malloc(sizeof(char) * len_all + 1);
	if (!(string))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		string[i] = s1[i];
		i++;
	}
	while (i < len_two)
		string[i++] = s2[j++];
	j = 0;
	while (i < len_all)
		string[i++] = s3[j++];
	string[i] = 0;
	return (string);
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
	return (0);
}
