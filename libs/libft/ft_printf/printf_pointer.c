/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:32:06 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:18:06 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_hex_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (len);
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

void	print_hex(unsigned long long ptr, char type)
{
	if (ptr >= 16)
	{
		print_hex(ptr / 16, type);
		print_hex(ptr % 16, type);
	}
	else
	{
		if (ptr > 9)
		{
			if (type == 'x')
				ft_putchar_fd(ptr - 10 + 'a', 1);
			else
				ft_putchar_fd(ptr - 10 + 'A', 1);
		}
		else
			ft_putchar_fd(ptr + '0', 1);
	}
}

int	ft_print_pointer(unsigned long long ptr, char *flags)
{
	int	len;
	int	fmw;

	if (!ptr)
		return (ft_print_str("(nil)", flags));
	len = ft_hex_len(ptr) + 2;
	fmw = ft_get_fmw(flags, 'x');
	if (ft_has_flag(flags, '-') && fmw != 0)
	{
		ft_putstr_fd("0x", 1);
		print_hex(ptr, 'x');
		len += fill_fmw(len, fmw, flags);
	}
	else if (fmw > 0)
	{
		len += fill_fmw(len, fmw, flags);
		ft_putstr_fd("0x", 1);
		print_hex(ptr, 'x');
	}
	else
	{
		ft_putstr_fd("0x", 1);
		print_hex(ptr, 'x');
	}
	return (len);
}
