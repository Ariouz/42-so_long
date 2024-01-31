/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:40:28 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:17:47 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_int_len(long long i)
{
	int	len;

	len = 0;
	if (i <= 0)
	{
		len++;
		i = -i;
	}
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

static int	get_additional_flags_len(long long i, char *flags)
{
	if ((ft_has_flag(flags, ' ') && !ft_has_flag(flags, '+')))
		if (i >= 0)
			return (1);
	if (ft_has_flag(flags, '+') && i >= 0)
		return (1);
	return (0);
}

static void	print_decimal_wth_flags(long long i, char *flags)
{
	if (ft_has_flag(flags, ' ') && !ft_has_flag(flags, '+'))
	{
		if (i >= 0)
			ft_putchar_fd(' ', 1);
		ft_printnbr(i);
	}
	else if (ft_has_flag(flags, '+'))
	{
		if (i >= 0)
			ft_putchar_fd('+', 1);
		ft_printnbr(i);
	}
	else
		ft_printnbr(i);
}

int	ft_print_decimal(int i, char *flags)
{
	int		len;
	int		fmw;
	long	l;

	l = (long long) i;
	len = ft_int_len(i) + get_additional_flags_len(l, flags);
	fmw = ft_get_fmw(flags, 'd');
	if (ft_has_flag(flags, '-'))
	{
		print_decimal_wth_flags(l, flags);
		len += fill_fmw(len, fmw, flags);
	}
	else if (fmw != 0)
	{
		len += fill_fmw(len, fmw, flags);
		if (l < 0 && (flags[0] == '0' || ft_has_flag(flags, '.')))
		{
			ft_putchar_fd('-', 1);
			l = -l;
		}
		print_decimal_wth_flags(l, flags);
	}
	else
		print_decimal_wth_flags(l, flags);
	return (len);
}

void	ft_printnbr(long n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
	}
	ft_putchar_fd(n % 10 + '0', 1);
}
