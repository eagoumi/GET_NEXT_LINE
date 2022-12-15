/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:17:33 by ayagoumi          #+#    #+#             */
/*   Updated: 2022/12/15 22:17:33 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *string)
{
	int	count;

	count = 0;
	while (string[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
