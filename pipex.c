/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:54:04 by rchmouk           #+#    #+#             */
/*   Updated: 2023/01/30 08:38:09 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmp_path(char *s)
{
	if (s[0] == 'P' && s[1] == 'A' && s[2] == 'T' && s[3] == 'H' && s[4] == '=')
		return (1);
	return (0);
}

int	serch_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (cmp_path(env[i]) == 1)
			return (i);
		i++;
	}
	return (-1);
}

void	exit_and_error(void)
{
	perror("Error");
	exit(1);
}

char	*ft_try_path(char **path, char *cmd)
{
	int		i;
	char	*str;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	if (cmd[0] == '/')
		return (NULL);
	while (path[i])
	{
		str = ft_strjoin(path[i], cmd);
		if (access(str, X_OK) == 0)
			break ;
		i++;
	}
	if (access(str, X_OK) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
	return (str);
}

int	main(int ac, char **av, char **env)
{
	int	id;
	int	id2;
	int	fd1;
	int	fd2;
	int	fd[2];

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			return (1);
		fd1 = open(av[1], O_RDONLY);
		if (fd1 < 0)
			exit_and_error();
		id = fork();
		if (id == 0)
			ft_infile(av, fd1, env, fd);
		fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd2 < 0)
			exit_and_error();
		id2 = fork();
		if (id2 == 0)
			ft_outfile(av, fd2, env, fd);
		close_and_wait(fd, id, id2);
	}
}
