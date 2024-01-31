/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:24:01 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/15 14:37:35 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dst;

	i = 0;
	dst = ft_calloc(ft_strlen((char *)s) + 1, sizeof(unsigned char));
	if (!dst)
		return (NULL);
	while (*(unsigned char *)(s + i))
	{
		dst[i] = *(unsigned char *)(s + i);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
