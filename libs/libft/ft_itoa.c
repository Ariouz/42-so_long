/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:47:58 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/08 11:58:09 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len(long nb)
{
	size_t		i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		i = 1;
	}
	if (nb == 0)
		i = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	int		len;
	char	*result;

	len = ft_n_len((long)n);
	i = 0;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	nb = (long)n;
	if (n < 0)
	{
		result[i] = '-';
		nb = -nb;
		i++;
	}
	result[len] = '\0';
	while (len != i)
	{
		result[len - 1] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (result);
}
