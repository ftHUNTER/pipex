/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:54:27 by rchmouk           #+#    #+#             */
/*   Updated: 2023/01/27 19:53:23 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (0);
	p = malloc(size * count);
	if (!p)
		return (0);
	while (i < size * count)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
