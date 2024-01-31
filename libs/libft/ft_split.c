/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:26:35 by vicalvez          #+#    #+#             */
/*   Updated: 2023/11/29 10:38:26 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_get_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_get_word(const char *s, char c)
{
	int		word_len;
	char	*word;

	word_len = ft_get_word_len(s, c);
	word = ft_substr((char *)s, 0, word_len);
	if (!word)
	{
		return (NULL);
	}
	else
		word[word_len] = 0;
	return (word);
}

static char	**ft_check_and_result(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = ft_check_and_result(s, c);
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			result[j] = ft_get_word((char *)(s + i), c);
			i += ft_get_word_len((char *)(s + i), c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	result[j] = NULL;
	return (result);
}
