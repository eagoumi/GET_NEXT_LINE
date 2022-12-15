#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>


# define BUFFER_SIZE 5

int		ft_strlen();
char	*ft_strdup();

char	*get_next_line(int fd);

#endif