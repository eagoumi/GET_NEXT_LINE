/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:24:20 by ayagoumi          #+#    #+#             */
/*   Updated: 2022/12/15 22:24:20 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 5

char	*ft_strdup(const char *s1);
int		ft_strlen(char *string);

char	*get_next_line(int fd);

#endif