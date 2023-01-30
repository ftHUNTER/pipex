/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:53:10 by rchmouk           #+#    #+#             */
/*   Updated: 2023/01/30 08:37:55 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile(char **av, int fd1, char **env, int *fd)
{
	char	**str;
	char	**cmd1;
	int		x;

	x = serch_path(env);
	cmd1 = ft_split(av[2], ' ');
	if (dup2(fd1, 0) == -1)
		exit_and_error();
	if (dup2(fd[1], 1) == -1)
		exit_and_error();
	if (x == -1 && access(cmd1[0], X_OK) == 0)
		execve(cmd1[0], cmd1, env);
	if (x == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
	str = ft_split(&env[x][5], ':');
	close(fd[0]);
	execve(ft_try_path(str, cmd1[0]), cmd1, env);
}

void	ft_outfile(char **av, int fd2, char **env, int *fd)
{
	char	**str;
	char	**cmd2;
	int		x;

	(void)fd2;
	x = serch_path(env);
	cmd2 = ft_split(av[3], ' ');
	if (dup2(fd[0], 0) == -1)
		exit_and_error();
	if (dup2(fd2, 1) == -1)
		exit_and_error();
	if (x == -1 && access(cmd2[0], X_OK) == 0)
		execve(cmd2[0], cmd2, env);
	if (x == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
	str = ft_split(&env[x][5], ':');
	close(fd[1]);
	execve(ft_try_path(str, cmd2[0]), cmd2, env);
}

void	close_and_wait(int *fd, int id, int id2)
{
	close(fd[1]);
	close(fd[0]);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
}
