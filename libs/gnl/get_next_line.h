/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:28:28 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/15 11:48:01 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		gnl_ft_strlen(char *s);
char	*get_next_line(int fd);
char	*gnl_ft_substr(char const *s, size_t start, size_t len);
char	*gnl_ft_strchr(const char *s, int c);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif
