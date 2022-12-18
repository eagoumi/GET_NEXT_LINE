/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:24:20 by eagoumi          #+#    #+#             */
/*   Updated: 2022/12/15 22:24:20 by eagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
// # define BUFFER_SIZE 5

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *string);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *ch, int s);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif