/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:01:07 by rchmouk           #+#    #+#             */
/*   Updated: 2023/01/27 19:52:39 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s3;
	int		j;

	if (!s1 || !s2)
		return (0);
	j = ft_strlen(s1);
	i = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!s3)
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	s3[j++] = '/';
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	return (s3[j] = '\0', s3);
}
