/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:45:46 by ayagoumi          #+#    #+#             */
/*   Updated: 2022/12/15 21:45:46 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			i;
	static char	*readed_line;
	size_t		read_line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line = read(fd, &buffer, BUFFER_SIZE);
	while (read_line > 0)
	{
		readed_line[i++] = *buffer;
		if (*buffer == '\n')
			break ;
		read_line = read(fd, &buffer, BUFFER_SIZE);
	}
	readed_line[i] = '\0';
	if (read_line <= 0 && i == 0)
		return (NULL);
	/* /!\ Still need to free buffer allocated*/
	ft_strdup (readed_line);
	return (readed_line);
}
