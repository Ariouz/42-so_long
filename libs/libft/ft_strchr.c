/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:54:25 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/22 13:11:33 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <string.h>*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = 0;
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
/*
int main(void)
{
	char *s = "tripouille";
	printf("%i\n", 't' + 256);
	printf("%s\n", strchr(s, 't' + 256));
	printf("%s\n", ft_strchr(s, 't' + 256));
	return (0);
}*/
