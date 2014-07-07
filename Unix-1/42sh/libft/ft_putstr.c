#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

void	ft_putstr(char *str, int fd)
{
  if (str != NULL)
    (void)write(fd, str, ft_strlen(str));
}
