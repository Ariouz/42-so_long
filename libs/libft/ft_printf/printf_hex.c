/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:51:36 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:18:03 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_add_0x(char *flags, char type)
{
	if (ft_has_flag(flags, '#'))
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(type, 1);
		return (2);
	}
	return (0);
}

int	ft_print_hex(unsigned int hex, char *flags, char type)
{
	int	len;
	int	fmw;

	if (!hex)
		return (write(1, "0", 1));
	len = ft_hex_len(hex);
	fmw = ft_get_fmw(flags, 'p');
	if (ft_has_flag(flags, '-') && fmw != 0)
	{
		len += ft_add_0x(flags, type);
		print_hex((unsigned long long) hex, type);
		len += fill_fmw(len, fmw, flags);
	}
	else if (fmw > 0)
	{
		len += fill_fmw(len, fmw, flags);
		len += ft_add_0x(flags, type);
		print_hex((unsigned long long) hex, type);
	}
	else
	{
		len += ft_add_0x(flags, type);
		print_hex((unsigned long long) hex, type);
	}
	return (len);
}
