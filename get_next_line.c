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
#include <stdbool.h>

char	*get_next_line(int fd)
{
	
	char		*buffer;
	int			i;
	static char	readed_line[70000];
	size_t		read_line;
	bool new = false;
	// printf("ssdsd");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	// printf("ssdsd");
	read_line = read(fd, buffer, BUFFER_SIZE);
	size_t k;
	while (read_line > 0)
	{	
		k = 0;
		while(k < read_line){
			readed_line[i] = buffer[k];
			if (buffer[k] == '\n')
				new = true;
			i++;
			k++;
		}
		if (new == true)
			break;
		read_line = read(fd, buffer, BUFFER_SIZE);

	}
	readed_line[i] = '\0';
	free (buffer);
	if (read_line <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(readed_line));
}
// int main()
// {
// 	// printf("ssdsd");
// 	int fd = open("ssss.txt", O_RDONLY);
// 	// get_next_line(line);

// 		char *line = get_next_line(fd);
// 		printf("%s", line);
// }