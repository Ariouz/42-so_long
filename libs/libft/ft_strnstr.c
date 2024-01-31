/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:28:17 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/08 13:08:04 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen((char *) little) == 0)
		return ((char *) big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < n)
		{
			if (little[j + 1] == 0)
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
