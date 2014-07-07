#include <stdarg.h>
#include "ft.h"
int    	print_nbr_arg(int nbr, va_list ap)
{
  int	res;

  res = 0;
  if (nbr == 1 || nbr == 2 || nbr == 4)
    res += ft_putnbr(va_arg(ap, int));
  else if (nbr == 3)
    res += nbr_tobase(va_arg(ap, int), "01234567", "");
  else if (nbr == 5)
    res += nbr_tobase(va_arg(ap, int), "0123456789abcdef", "");
  else if (nbr == 6)
    res += nbr_tobase(va_arg(ap, int), "0123456789ABCDEF", "");
  else if (nbr == 8)
    res += nbr_tobase(va_arg(ap, int), "01", "");
  else if (nbr == 0)
    res += ft_putchar(va_arg(ap, int));
  else if (nbr == 7)
    res += nbr_tobase(va_arg(ap, int), "0123456789abcdef", "0x");
  return (res);
}
