/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:31:24 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/08 13:37:40 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*next;

	size = 0;
	if (lst)
	{
		size = 1;
		if (lst->next == NULL)
			return (size);
		next = lst->next;
		while (next != NULL)
		{
			next = next->next;
			size++;
		}
	}
	return (size);
}
