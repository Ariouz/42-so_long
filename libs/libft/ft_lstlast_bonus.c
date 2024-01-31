/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:33:56 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/14 23:42:49 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*next;

	if (lst)
	{
		if (lst->next == NULL)
			return (lst);
		next = lst->next;
		while (next != NULL && next->next != NULL)
			next = next->next;
		return (next);
	}
	return (NULL);
}
