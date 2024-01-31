/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:58:55 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/22 13:10:41 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*dst;

	i = 0;
	s = (unsigned char *) src;
	dst = (unsigned char *) dest;
	if ((!src && !dest) || n == 0)
		return (dest);
	if (dst > s)
		while (n-- > 0)
			dst[n] = s[n];
	else
	{
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*int main(void){
	char dest[15];
	char *src = "Salut";
	printf("%p\n", ft_memmove(dest, src, 5));
}*/
