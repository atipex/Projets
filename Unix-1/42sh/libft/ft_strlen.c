#include <stdlib.h>
#include "lib.h"

int	ft_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i++])
      ;
  return (i - 1);
}
