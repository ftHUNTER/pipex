/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:53:06 by rchmouk           #+#    #+#             */
/*   Updated: 2023/01/28 09:57:00 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_infile(char **av, int fd1, char **env, int *fd);
char	*ft_try_path(char **path, char *cmd);
int		serch_path(char **env);
int		cmp_path(char *s);
void	ft_outfile(char **av, int fd2, char **env, int *fd);
void	close_and_wait(int *fd, int id, int id2);
void	exit_and_error(void);

#endif