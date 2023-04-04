// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H
// #endif

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 1024

// #include <unistd.h> // For read
// #include <stdlib.h> // For malloc && free

// char    *get_next_line(int fd);
// #endif

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i = 0;
	int		byte;
	char	*buf;
	char	c;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);

	buf = malloc(sizeof(char) * 1000);
	byte = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1);
	if (byte <= 0)
		return (free(buf), NULL);
	while (byte > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
		byte = read(fd, &c, 1);
	}
	buf[i] = '\0'; // may be byte0 but idx100
	return (buf);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
    int fd;
    char *line;
    fd = open("text", O_RDWR);
    line = get_next_line(fd);
    printf("%s", line);
    free (line);
    line = get_next_line(fd);
    printf("%s", line);
    free (line);
    line = get_next_line(fd);
    printf("%s", line);
    free (line);
    line = get_next_line(fd);
    printf("%s", line);
    free (line);
    close(fd);
}