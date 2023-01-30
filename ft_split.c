/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:59:27 by rchmouk           #+#    #+#             */
/*   Updated: 2023/01/27 19:52:41 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count(char const *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			nb++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static char	*alloc(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!(ptr))
	{
		free(ptr);
		return (NULL);
	}
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

static char	**frr(char **ptr, int i)
{
	while (--i >= 0)
	{
		free(ptr[i]);
		ptr[i] = 0;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb;
	char	**ptr;

	if (!s)
		return (0);
	nb = ft_count(s, c);
	ptr = ft_calloc(sizeof(char *), (nb + 1));
	if (!(ptr))
		return (NULL);
	i = -1;
	while (++i < nb)
	{
		while (s[0] == c)
			s++;
		ptr[i] = alloc(s, c);
		if (ptr[i] == 0)
			return (frr(ptr, i));
		s += ft_strlen(ptr[i]);
	}
	return (ptr[i] = 0, ptr);
}
