/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:11:35 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:17:59 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_global(va_list args, t_list *format_args, const char *s)
{
	int		len;
	int		i;
	t_list	*arg;

	len = 0;
	i = 0;
	arg = format_args->next;
	while (s[i])
	{
		if (s[i] == '%' && arg != NULL)
		{
			len += ft_print_arg(args, (t_arg *) arg->content);
			i += ((t_arg *) arg->content)->arg_len;
			arg = arg->next;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}
