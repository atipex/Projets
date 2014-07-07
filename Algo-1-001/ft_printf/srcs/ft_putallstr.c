#include <stdio.h>
#include "ft.h"

int	ft_putallstr(char *str)
{
  int	c;
  int	res;

  c = 0;
  res = 0;
  while (str[c])
    {
      if (str[c] < 32 || str[c] >= 127)
	res += nbr_tobase(str[c], "01234567", "\\0");
      else
	res += ft_putchar(str[c]);
      c += 1;
    }
  return (res);
}
