/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:47:20 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/22 15:53:38 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dlen;
	unsigned int	j;
	unsigned int	res;

	dlen = 0;
	j = 0;
	res = 0;
	while (dst[dlen])
		dlen++;
	while (src[res])
		res++;
	if (size <= dlen)
		res += size;
	else
		res += dlen;
	while (src[j] && dlen + 1 < size)
		dst[dlen++] = src[j++];
	dst[dlen] = '\0';
	return (res);
}
