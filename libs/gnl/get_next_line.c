/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:48:10 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/15 11:49:25 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <string.h>

char	*get_next_eol(int fd, char *str)
{
	char	*buffer;
	int		read_res;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_res = 1;
	while (!gnl_ft_strchr(str, '\n') && read_res != 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_res] = 0;
		str = gnl_ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	s = gnl_ft_substr(str, 0, i + 1);
	if (!s)
		return (NULL);
	return (s);
}

char	*rem_previous_line(char *str, char *line)
{
	char	*ret;

	if (!str[gnl_ft_strlen(line)])
	{
		free(str);
		return (NULL);
	}
	ret = gnl_ft_substr(str, gnl_ft_strlen(line), gnl_ft_strlen(str) - gnl_ft_strlen(line));
	free(str);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str[10000];
	char		*line;

	str[fd] = get_next_eol(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = rem_previous_line(str[fd], line);
	return (line);
}

/*int main()
{
	int     fd;
	int		fd2;
	int		use_standard = 0;
	
	if (use_standard)
		fd = 0;
	else
		fd = open("test.txt", O_RDONLY);
	
	if (fd == -1)
	{
		perror("Erreur sur le fd");
		return (1);
	}
	
	char *line;
	
	line = get_next_line(fd);
	printf("Ligne lue |%s", line);
	free(line);
	
	fd2 = open("test2", O_RDONLY);
	line = get_next_line(fd2);
	printf("Ligne lue |%s", line);
	free(line);

	line = get_next_line(fd2);
	printf("Ligne lue |%s", line);
	free(line);

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Ligne lue |%s", line);
		free(line);
		line = get_next_line(fd);
	}

	return (0);
}*/