/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:40:52 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/08 15:03:47 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*next;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		next = ft_lstnew((*f)(lst->content));
		if (!next)
		{
			while (first)
			{
				next = first->next;
				(*del)(first->content);
				free(first);
				first = next;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, next);
		lst = lst->next;
	}
	return (first);
}
