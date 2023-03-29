#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024

#include <unistd.h> // For read
#include <stdlib.h> // For malloc && free

char    *get_next_line(int fd);

#endif