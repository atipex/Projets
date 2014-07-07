#include <unistd.h>
#include "lib.h"

void	ft_putchar(char c)
{
  (void)write(1, &c, 1);
}
