/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:05:26 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/15 18:03:16 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	ft_get_trim_size(char *result, int len, const char *set)
{
	while (result[len - 1] && ft_strchr(set, result[len - 1]) != NULL)
	{
		result[len - 1] = 0;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*f_res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s1);
	while (*(unsigned char *)(s1 + i) &&
		ft_strchr(set, *(unsigned char *)(s1 + i)) != NULL)
	{
		i++;
	}
	len -= i;
	result = ft_substr(s1, i, len);
	if (!result)
		return (NULL);
	f_res = ft_substr(result, 0, ft_get_trim_size(result, len, set));
	free(result);
	return (f_res);
}
