/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:45:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/15 02:40:45 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	p_fd[2];
	int	pid1;
	int	fd_in;
	int	fd_out;

	if (argc != 5)
		return (pip_error(1));
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_in < 0 || fd_out < 0)
		return (pip_error(2));
	if (pipe(p_fd) == -1)
		return (3);
	pid1 = fork();
	if (pid1 == -1)
		return (4);
	if (pid1 == 0)
		child_process(argv, p_fd, env, fd_in);
	dup2(fd_out, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	close(p_fd[0]);
	execute(argv[3], env);
}

void	child_process(char **argv, int *p_fd, char **env, int fd_in)
{
	dup2(fd_in, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	close(p_fd[1]);
	execute(argv[2], env);
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
