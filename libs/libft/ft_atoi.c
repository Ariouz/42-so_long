/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:44:49 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/08 12:24:09 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_atoi_sign(int *sign, int *i, const char *nptr)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (!ft_isdigit(nptr[i]) && nptr[i] != '+' && nptr[i] != '-')
	{
		if ((!(nptr[i] >= 9 && nptr[i] <= 13) && nptr[i] != 32)
			|| ft_strlen((char *)nptr) == 0)
			return (0);
		i++;
	}
	ft_atoi_sign(&sign, &i, nptr);
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}
