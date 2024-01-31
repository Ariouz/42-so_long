/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:33:39 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:17:43 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_arg_len(t_list *formats, const char *s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (ft_get_format_type(formats, s[i]) != NULL)
			return (i);
		i++;
	}
	return (i);
}

static t_arg	*ft_create_arg(t_list *formats,
	const char *s, int i, int arg_len)
{
	t_arg	*arg;

	arg = (t_arg *) malloc(sizeof(t_arg));
	arg->arg = ft_substr(s, i + 1, arg_len);
	arg->flags = ft_substr(s, i + 1, arg_len - 1);
	arg->arg_len = arg_len;
	arg->format = ft_get_format_type(formats, s[i + arg_len]);
	return (arg);
}

static t_list	*ft_split_args(t_list *formats, const char *s)
{
	t_list	*args;
	t_list	*new_arg;
	t_arg	*arg;
	int		i;
	int		arg_len;

	i = -1;
	args = (t_list *) malloc(sizeof(t_list));
	args->content = NULL;
	args->next = NULL;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			arg_len = get_arg_len(formats, s + i);
			new_arg = ft_lstnew(args);
			arg = ft_create_arg(formats, s, i, arg_len);
			new_arg->content = arg;
			ft_lstadd_back(&args, new_arg);
			i += arg_len;
		}
	}
	return (args);
}

int	ft_print_arg(va_list args, t_arg *arg)
{
	char	type;

	type = arg->format->type;
	if (type == 'c')
		return (ft_print_char(va_arg(args, int), arg->flags));
	if (type == 's')
		return (ft_print_str(va_arg(args, char *), arg->flags));
	if (type == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long long), arg->flags));
	if (type == 'd' || type == 'i')
		return (ft_print_decimal(va_arg(args, int), arg->flags));
	if (type == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int), arg->flags));
	if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(args, int), arg->flags, arg->format->type));
	if (type == '%')
		return (ft_print_char('%', arg->flags));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_list	*formats;
	t_list	*format_args;
	int		len;
	va_list	args;

	len = 0;
	formats = get_formats();
	va_start(args, s);
	format_args = ft_split_args(formats, s);
	len += ft_print_global(args, format_args, s);
	ft_lstclear(&format_args, ft_free_args);
	ft_lstclear(&formats, ft_free_formats);
	free(format_args);
	free(formats);
	va_end(args);
	return (len);
}
