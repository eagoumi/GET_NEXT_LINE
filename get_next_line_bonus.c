/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:46:39 by eagoumi           #+#    #+#             */
/*   Updated: 2022/12/18 18:46:39 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"
#include <stdbool.h>

char	*ft_malloc(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char	*ft_reded_line(int fd, char *readed_line)
{
	char		*buffer;
	ssize_t		read_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_malloc(BUFFER_SIZE);
	read_line = read(fd, buffer, BUFFER_SIZE);
	while (read_line > 0)
	{	
		buffer[read_line] = '\0';
		readed_line = ft_strjoin(readed_line, buffer);
		if (readed_line == NULL)
			return (NULL);
		if (ft_strchr(readed_line, '\n'))
			break ;
		read_line = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (read_line < 0 || !readed_line || readed_line[0] == '\0')
	{
		free(readed_line);
		readed_line = NULL;
		return (NULL);
	}
	return (readed_line);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*readed_line[10240];
	char		*temp;
	char		*temp1;

	readed_line[fd] = ft_reded_line(fd, readed_line[fd]);
	if (readed_line[fd] == NULL)
		return (NULL);
	i = 0;
	while (readed_line[fd][i] != '\0' && readed_line[fd][i] != '\n')
		i++;
	if (readed_line[fd][i] != '\0')
		i++;
	temp1 = ft_substr(readed_line[fd], 0, i);
	if (temp1 == NULL)
	{
		free (readed_line[fd]);
		return (NULL);
	}
	temp = readed_line[fd];
	readed_line[fd] = ft_substr(readed_line[fd], i, (ft_strlen(temp) - i));
	free(temp);
	if (readed_line[fd] == NULL)
		return (NULL);
	return (temp1);
}
