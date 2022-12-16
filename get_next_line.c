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
	int i;
	static char	*readed_line = NULL;
	char	*temp;
	char	*temp1;
	ssize_t		read_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_line = read(fd, buffer, BUFFER_SIZE);
	while (read_line > 0)
	{	
		buffer[read_line] = '\0';
		readed_line = ft_strjoin(readed_line, buffer);
		if (readed_line == NULL)
			return (NULL);
		if (ft_strchr(readed_line, '\n'))
			break;
		read_line = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (read_line < 0 || !readed_line || readed_line[0] == '\0')
	{
		free(readed_line);
		readed_line = NULL;
		return(NULL);
	}
	i = 0;
	while (readed_line[i] != '\0' && readed_line[i] != '\n')
		i++;
	if (readed_line[i] != '\0')
		i++;
	temp1 = ft_substr(readed_line, 0, i);
	if (temp1 == NULL)
		return (NULL);
	temp = readed_line;
	readed_line = ft_substr(readed_line, i, (ft_strlen(temp) - i));
	free(temp);
	if (readed_line == NULL)
		return (NULL);
	// check if line containe '\n'	return th efirst part! the left part you store it in readed_line
	return (temp1);
}
// int main()
// {
// 	int fd = open("ssss.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 	}
// // 	int fd1 = open("ssss.txt", O_RDONLY);
// // 	char *line2 = get_next_line(fd1);
// // 	printf("%s\n", line2);
// // 	int fd3 = open("ssss.txt", O_RDONLY);
// // 	char *line3 = get_next_line(fd3);
// // 	printf("%s\n", line3);
// // 	int fd4 = open("ssss.txt", O_RDONLY);
// // 	char *line4 = get_next_line(fd4);
// // 	printf("%s\n", line4);
// // 	int fd11 = open("ssss.txt", O_RDONLY);
// // 	char *line21 = get_next_line(fd11);
// // 	printf("%s\n", line21);
// // 	int fd31 = open("ssss.txt", O_RDONLY);
// // 	char *line31 = get_next_line(fd31);
// // 	printf("%s\n", line31);
// // 	int fd3111 = open("ssss.txt", O_RDONLY);
// // 	char *line3111 = get_next_line(fd3111);
// // 	printf("%s\n", line3111);
// // 	int fd31110 = open("ssss.txt", O_RDONLY);
// // 	char *line31110 = get_next_line(fd31110);
// // 	printf("%s\n", line31110);
// }