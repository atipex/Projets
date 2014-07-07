
#include "ft.h"
int	ft_putstr(char *s)
{
  int	counter;

  counter = 0;
  while (s[counter])
    {
      ft_putchar(s[counter]);
      counter += 1;
    }
  return (counter);
}
