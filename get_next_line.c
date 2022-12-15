#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd)
{
    char    *buffer;
    int     i;
    char    *readed_line;

    buffer = (char)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    read_line = (int)read(fd, &buffer ,BUFFER_SIZE);
    while(read_line > 0)
    {
        readed_line[i++] = buffer; 
        if (buffer == '\n')
            break;
        read_line = (int)read(fd, &buffer ,BUFFER_SIZE); // if the line are not yet in the new line
    }
    readed_line[i] = '\0';
    if (b <= 0 && i == 0) // protection for readed_line into while if read_line have an empty line
        return(NULL);
    // /!\ Still need to free buffer allocated 
    ft_strdup(readed_line);
    return(readed_line);
}