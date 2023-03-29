// #include <unistd.h> // For read
// #include <stdlib.h> // For malloc && free

// // #define BUFFER_SIZE 1024

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		index;
	int		byte;
	char	*buffer;
	char	character;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	index = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte = read(fd, &character, 1);
	if (byte <= 0)// nothing was made AT ALL, extreme chedck
		return (free(buffer), NULL);
	while (byte > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
		byte = read(fd, &character, 1);
	}
	//if ((byte <= 0) && (index == 0)) // nothing was made AT ALL, extreme chedck
	//	return (free(buffer), NULL);
	buffer[index] = '\0'; // may be byte0 but idx100
	return (buffer);
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