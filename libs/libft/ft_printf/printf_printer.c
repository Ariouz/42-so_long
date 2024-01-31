/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:33:41 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:18:10 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_char(char c, char *flags)
{
	int	len;
	int	fmw;

	len = 1;
	fmw = ft_get_fmw(flags, 'c');
	if (ft_has_flag(flags, '-') && fmw != 0)
	{
		ft_putchar_fd(c, 1);
		len += fill_fmw(1, fmw, flags);
	}
	else if (fmw > 0)
	{
		len += fill_fmw(1, fmw, flags);
		ft_putchar_fd(c, 1);
	}
	else
		ft_putchar_fd(c, 1);
	return (len);
}

int	ft_print_str_two(char *s, char *flags)
{
	int	len;
	int	fmw;

	len = ft_strlen(s);
	fmw = ft_get_fmw(flags, 's');
	if (ft_has_flag(flags, '-') && fmw != 0)
	{
		ft_putstr_fd(s, 1);
		len += fill_fmw(len, fmw, flags);
	}
	else if (fmw > 0)
	{
		len += fill_fmw(len, fmw, flags);
		ft_putstr_fd(s, 1);
	}
	else
		ft_putstr_fd(s, 1);
	return (len);
}

int	ft_print_str(char *s, char *flags)
{
	int	allocate;
	int	res;

	allocate = 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		allocate = 1;
	}
	res = ft_print_str_two(s, flags);
	if (allocate)
		free(s);
	return (res);
}
