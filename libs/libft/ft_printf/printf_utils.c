/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:33:33 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:18:26 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_add_format(t_list **formats, char type)
{
	t_list		*new_;
	t_format	*format;

	new_ = ft_lstnew(formats);
	format = (t_format *) malloc(sizeof(t_format));
	format->type = type;
	new_->content = format;
	new_->next = NULL;
	ft_lstadd_front(formats, new_);
}

t_list	*get_formats(void)
{
	t_list	*formats;

	formats = (t_list *) malloc(sizeof(t_list));
	formats->content = NULL;
	formats->next = NULL;
	ft_add_format(&formats, 'c');
	ft_add_format(&formats, 's');
	ft_add_format(&formats, 'p');
	ft_add_format(&formats, 'd');
	ft_add_format(&formats, 'i');
	ft_add_format(&formats, 'u');
	ft_add_format(&formats, 'x');
	ft_add_format(&formats, 'X');
	ft_add_format(&formats, '%');
	return (formats);
}

t_format	*ft_get_format_type(t_list *formats, char c)
{
	t_list		*next;
	t_format	*f;

	if (!formats)
		return (NULL);
	next = formats;
	while (next != NULL)
	{
		f = (t_format *) next->content;
		if (!f || !f->type)
			return (NULL);
		if (f->type == c)
			return (f);
		next = next->next;
	}
	return (NULL);
}

int	ft_has_flag(char *flags, char c)
{
	return (ft_strchr(flags, c) != NULL);
}

int	ft_get_fmw(char *flags, char type)
{
	int	fmw;
	int	i;

	i = 0;
	while (flags[i])
	{
		if (ft_isdigit(flags[i]) && (flags[i - 1] != '.' || type == 'd'))
			break ;
		i++;
	}
	fmw = ft_atoi(flags + i);
	return (fmw);
}
