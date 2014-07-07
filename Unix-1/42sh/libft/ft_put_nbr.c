#include "lib.h"

void	ft_put_nbr(int nbr)
{
  if (nbr >= 10 || nbr <= -10)
    ft_put_nbr(nbr / 10);
  else if (nbr < 0)
    ft_putchar('-');
  if (nbr > 0)
    ft_putchar('0' + (nbr % 10));
  else
    ft_putchar('0' - (nbr % 10));
}
