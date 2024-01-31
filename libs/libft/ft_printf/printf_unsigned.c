/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:27:17 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:18:16 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_unsigned_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_unsigned_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

static char	*process_unsigned(unsigned int n)
{
	char	*num;

	if (n == 0)
		num = ft_strdup("0");
	else
		num = ft_uitoa(n);
	return (num);
}

int	ft_print_unsigned_int(unsigned int n, char *flags)
{
	int		len;
	char	*nb;

	len = 0;
	nb = process_unsigned(n);
	len += ft_print_str(nb, flags);
	free(nb);
	return (len);
}
