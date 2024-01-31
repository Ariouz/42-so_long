/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:07:13 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:17:57 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_absolute(int i)
{
	return (-i);
}

int	fill_fmw(int len, int fmw, char *flags)
{
	int		i;
	char	c;

	i = fmw;
	c = ' ';
	if (flags[0] == '0')
		c = '0';
	while (fmw > len)
	{
		ft_putchar_fd(c, 1);
		fmw--;
	}
	return (ft_absolute(fmw - i));
}
