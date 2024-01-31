/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:22:16 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/15 14:10:48 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c % 256)
			result = (char *)(s + i);
		i++;
	}
	if (c % 256 == 0)
		result = (char *)(s + i);
	return (result);
}
