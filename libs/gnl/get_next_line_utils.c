/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:39:12 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/15 11:48:34 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i])
	{
		if (s[i] == c % 256)
		{
			result = (char *)(s + i);
			break ;
		}
		i++;
	}
	if (c % 256 == 0)
	{
		result = (char *)(s + i);
	}
	return (result);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	dst = malloc(sizeof(char) * gnl_ft_strlen((char *)s1) + gnl_ft_strlen((char *)s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[++i])
	{
		dst[i] = s1[i];
	}
	while (s2[++j])
	{
		dst[i + j] = s2[j];
	}
	free(s1);
	dst[i + j] = 0;
	return (dst);
}

int	gnl_ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (size_t) gnl_ft_strlen((char *)s))
		len = 0;
	if (gnl_ft_strlen((char *)s) - start < len)
		len = gnl_ft_strlen((char *)s) - start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	if (len <= 0)
		return (sub);
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}